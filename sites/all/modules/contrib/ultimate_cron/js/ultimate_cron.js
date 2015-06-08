jQuery(document).ready(function($) {
  // @todo Make client side status switch work on all themes?
  return;

  $('a[href$="admin/config/system/cron"]').click(function() {
    $(".ultimate-cron-admin-status").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
  $('a[href$="admin/config/system/cron/overview/error"]').click(function() {
    $("tr .ultimate-cron-admin-status:not(.ultimate-cron-admin-status-error)").parent().hide();
    $("tr .ultimate-cron-admin-status-error").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
  $('a[href$="admin/config/system/cron/overview/warning"]').click(function() {
    $("tr .ultimate-cron-admin-status:not(.ultimate-cron-admin-status-warning)").parent().hide();
    $("tr .ultimate-cron-admin-status-warning").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
  $('a[href$="admin/config/system/cron/overview/info"]').click(function() {
    $("tr .ultimate-cron-admin-status:not(.ultimate-cron-admin-status-info)").parent().hide();
    $("tr .ultimate-cron-admin-status-info").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
  $('a[href$="admin/config/system/cron/overview/success"]').click(function() {
    $("tr .ultimate-cron-admin-status:not(.ultimate-cron-admin-status-success)").parent().hide();
    $("tr .ultimate-cron-admin-status-success").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
  $('a[href$="admin/config/system/cron/overview/running"]').click(function() {
    $("tr .ultimate-cron-admin-status:not(.ultimate-cron-admin-status-running)").parent().hide();
    $("tr .ultimate-cron-admin-status-running").parent().show();
    $(this).parent().siblings().removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });
});
