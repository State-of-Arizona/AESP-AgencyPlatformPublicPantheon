<?php
/**
 * @file
 *
 * Class for handling background processes.
 */

/**
 * BackgroundProcess class.
 */
class BackgroundProcess {
  public $handle;
  public $connection;
  public $service_host;
  public $service_group;
  public $uid;

  public static function load($process) {
    $new = new BackgroundProcess($process->handle);
    @$new->callback = $process->callback;
    @$new->args = $process->args;
    @$new->uid = $process->uid;
    @$new->token = $process->token;
    @$new->service_host = $process->service_host;
    @$new->service_group = $process->service_group;
    @$new->exec_status = $process->exec_status;
    @$new->start_stamp = $process->start_stamp;
    @$new->status = $process->exec_status;
    @$new->start = $process->start_stamp;
    return $new;
  }

  /**
   * Constructor.
   *
   * @param type $handle
   *   Handle to use. Optional; leave out for auto-handle.
   */
  public function __construct($handle = NULL) {
    $this->handle = $handle ? $handle : background_process_generate_handle('auto');
    $this->token = background_process_generate_handle('token');
    $this->service_group = variable_get('background_process_default_service_group', 'default');
  }

  public function lock($status = BACKGROUND_PROCESS_STATUS_LOCKED) {
    // Preliminary select to avoid unnecessary write-attempt
    if (background_process_get_process($this->handle)) {
      // watchdog('bg_process', 'Will not attempt to lock handle %handle, already exists', array('%handle' => $this->handle), WATCHDOG_NOTICE);
      return FALSE;
    }

    // "Lock" handle
    $this->start_stamp = $this->start = microtime(TRUE);
    if (!background_process_lock_process($this->handle, $status)) {
      // If this happens, we might have a race condition or an md5 clash
      watchdog('bg_process', 'Could not lock handle %handle', array('%handle' => $this->handle), WATCHDOG_ERROR);
      return FALSE;
    }
    $this->exec_status = $this->status = BACKGROUND_PROCESS_STATUS_LOCKED;
    $this->sendMessage('locked');
    return TRUE;
  }

  /**
   * Start background process
   *
   * Calls the service handler through http passing function arguments as serialized data
   * Be aware that the callback will run in a new request
   *
   * @global string $base_url
   *   Base URL for this Drupal request
   *
   * @param $callback
   *   Function to call.
   * @param $args
   *   Array containg arguments to pass on to the callback.
   * @return mixed
   *   TRUE on success, NULL on failure, FALSE on handle locked.
   */
  public function start($callback, $args = array()) {
    if (!$this->lock()) {
      return FALSE;
    }

    return $this->execute($callback, $args);
  }

  public function queue($callback, $args = array()) {
    if (!$this->lock(BACKGROUND_PROCESS_STATUS_QUEUED)) {
      return FALSE;
    }

    $this->callback = $callback;
    $this->args = $args;

    if (!background_process_set_process($this->handle, $this->callback, $this->uid, $this->args, $this->token)) {
      // Could not update process
      return NULL;
    }

    module_invoke_all('background_process_pre_execute', $this->handle, $this->callback, $this->args, $this->token);

    // Initialize progress stats
    $old_db = db_set_active('background_process');
    progress_remove_progress($this->handle);
    db_set_active($old_db);

    $queues = variable_get('background_process_queues', array());
    $queue_name = isset($queues[$this->callback]) ? 'bgp:' . $queues[$this->callback] : 'background_process';
    $queue = DrupalQueue::get($queue_name);
    $queue->createItem(array(rawurlencode($this->handle), rawurlencode($this->token)));
    _background_process_ensure_cleanup($this->handle, TRUE);
  }


  public function determineServiceHost() {
    // Validate explicitly selected service host
    $service_hosts = background_process_get_service_hosts();
    if ($this->service_host && empty($service_hosts[$this->service_host])) {
      $this->service_host = variable_get('background_process_default_service_host', 'default');
      if (empty($service_hosts[$this->service_host])) {
        $this->service_host = NULL;
      }
    }

    // Find service group if a service host is not explicitly specified.
    if (!$this->service_host) {
      if (!$this->service_group) {
        $this->service_group = variable_get('background_process_default_service_group', 'default');
      }
      if ($this->service_group) {
        $service_groups = variable_get('background_process_service_groups', array());
        if (isset($service_groups[$this->service_group])) {
          $service_group = $service_groups[$this->service_group];

          // Default method if none is provided
          $service_group += array(
            'method' => 'background_process_service_group_round_robin'
          );
          if (is_callable($service_group['method'])) {
            $this->service_host = call_user_func($service_group['method'], $service_group);
            // Revalidate service host
            if ($this->service_host && empty($service_hosts[$this->service_host])) {
              $this->service_host = NULL;
            }
          }
        }
      }
    }

    // Fallback service host
    if (!$this->service_host || empty($service_hosts[$this->service_host])) {
      $this->service_host = variable_get('background_process_default_service_host', 'default');
      if (empty($service_hosts[$this->service_host])) {
        $this->service_host = 'default';
      }
    }

    return $this->service_host;
  }

  public function execute($callback, $args = array()) {
    $this->callback = $callback;
    $this->args = $args;
    if (!background_process_set_process($this->handle, $this->callback, $this->uid, $this->args, $this->token)) {
      // Could not update process
      return NULL;
    }

    module_invoke_all('background_process_pre_execute', $this->handle, $this->callback, $this->args, $this->token);

    // Initialize progress stats
    $old_db = db_set_active('background_process');
    progress_remove_progress($this->handle);
    db_set_active($old_db);

    $this->connection = FALSE;

    $this->determineServiceHost();

    return $this->dispatch();
  }

  function dispatch() {
    $this->sendMessage('dispatch');

    $handle = rawurlencode($this->handle);
    $token = rawurlencode($this->token);
    list($url, $headers) = background_process_build_request('bgp-start/' . $handle . '/' . $token, $this->service_host);

    background_process_set_service_host($this->handle, $this->service_host);

    $options = array('method' => 'POST', 'headers' => $headers);
    $result = background_process_http_request($url, $options);
    if (empty($result->error)) {
      $this->connection = $result->fp;
      _background_process_ensure_cleanup($this->handle, TRUE);
      return TRUE;
    }
    else {
      background_process_remove_process($this->handle);
      watchdog('bg_process', 'Could not call service %handle for callback %callback: !error', array('%handle' => $this->handle, '%callback' => $this->callback, '!error' => print_r($result, TRUE)), WATCHDOG_ERROR);
      // Throw exception here instead?
      return NULL;
    }
    return FALSE;
  }

  function sendMessage($action) {
    if (module_exists('nodejs')) {
      if (!isset($this->progress_object)) {
        if ($progress = progress_get_progress($this->handle)) {
          $this->progress_object = $progress;
          $this->progress = $progress->progress;
          $this->progress_message = $progress->message;
        }
        else {
          $this->progress = 0;
          $this->progress_message = '';
        }
      }
      $object = clone $this;
      $message = (object) array(
        'channel' => 'background_process',
        'data' => (object) array(
          'action' => $action,
          'background_process' => $object,
          'timestamp' => microtime(TRUE),
        ),
        'callback' => 'nodejsBackgroundProcess',
      );
      drupal_alter('background_process_message', $message);
      nodejs_send_content_channel_message($message);
    }
  }

}
