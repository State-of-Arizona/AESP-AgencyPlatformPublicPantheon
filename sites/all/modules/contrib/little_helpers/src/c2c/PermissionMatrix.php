<?php

namespace Drupal\little_helpers\c2c;

class PermissionMatrix {
  protected $roles = array();
  protected $perms = array();
  protected $set;
  protected $width_perm = 0;
  protected $width_role = array();
  protected $db;

  public static function create($roles, $permissions) {
    $class = get_called_class();
    return new $class(\Database::getConnection(), $roles, $permissions);
  }

  public static function createFromSystem() {
    $role_permissions = array();
    $db = \Database::getConnection();
    foreach ($db->query('SELECT rid, permission, module FROM {role_permission}') as $row) {
      $role_permissions[$row->rid][$row->module][$row->permission] = TRUE;
    }
    return self::create(user_roles(), $role_permissions);
  }

  public static function createFromFile($file) {
    $roles  = array();
    $matrix = array();
    // this redefines $roles and $matrix
    include $file;

    $sys_roles = array();
    $roles_perms = array();
    foreach (user_roles() as $rid => $role) {
      $sys_roles[$role] = $rid;
      $roles_perms[$rid] = array();
    }

    $index_to_rid = array();
    foreach ($roles as $role) {
      $index_to_rid[] = isset($sys_roles[$role]) ? $sys_roles[$role] : FALSE;
    }

    foreach ($matrix as $module => $perms) {
      foreach ($perms as $perm => $vals) {
        foreach ($vals as $col => $val) {
          if (isset($val) && $index_to_rid[$col]) {
            $roles_perms[$index_to_rid[$col]][$module][$perm] = $val;
          }
        }
      }
    }

    return self::create(user_roles(), $roles_perms);
  }

  public function __construct($db, $roles, $permissions = array()) {
    $this->db = $db;
    $this->roles = $roles;
    $this->perms = array();

    $modules = self::moduleList();
    foreach ($modules as $module => $module_name) {
      if ($defined_perms = module_invoke($module, 'permission')) {
        $perms = array();
        foreach ($defined_perms as $perm => $dontcare) {
          $this->width_perm = max(strlen($perm), $this->width_perm);
          $perms[] = $perm;
        }
        $this->perms[$module] = $perms;
      }
    }
    foreach ($roles as $r) {
      $this->width_role[] = max(strlen($r), 5);
    }
    $this->set = $permissions;
  }

  protected static function moduleList() {
    $info = system_get_info('module');
    $modules = array();
    foreach (module_implements('permission') as $module) {
      $modules[$module] = $info[$module]['name'];
    }
    asort($modules);
    return $modules;
  }

  public function printEmptyTable() {
    $module_info = system_get_info('module');

    $perm_padding = str_pad('', $this->width_perm + 10);
    $role_line = '';
    $rids = array();
    $i = 0;

    $perm_null_line = '';
    foreach ($this->roles as $rid => $role) {
      $rids[] = $rid;
      $role_line      .= str_pad("'$role', ", $this->width_role[$i  ] + 4);
      $perm_null_line .= str_pad("NULL,",     $this->width_role[$i++] + 4);
    }

    $lines = array();
    foreach ($this->perms as $module => $perms) {
      $lines[] = "  ),";
      $lines[] = "  // {$module_info[$module]['name']}";
      $lines[] = "  '$module' => array(";
      foreach ($perms as $i => $perm) {
        $p = str_pad("'$perm'", $this->width_perm + 2);
        $lines[] = "    $p => array($perm_null_line),";
      }
    }
    array_push($lines, array_shift($lines));
    $lines = implode("\n", $lines);

    echo "<?php\n\n";
    echo "\$roles = array(\n";
    echo "  $perm_padding    $role_line\n";
    echo ");\n";
    echo "\$matrix = array(\n";
    echo "$lines\n";
    echo ");\n";
  }

  public function enforce() {
    foreach ($this->set as $rid => $perms) {
      foreach ($perms as $module => $p) {
        foreach ($p as $perm => $v) {
          if (!isset($v))
            continue;
          if ($v) {
            $this->db->merge('role_permission')
              ->key(array('rid' => $rid, 'permission' => $perm))
              ->fields(array('module' => $module))
              ->execute();
          } else {
            $this->db->delete('role_permission')
              ->condition('rid', $rid)
              ->condition('permission', $perm)
              ->execute();
          }
        }
      }
    }
  }
}

