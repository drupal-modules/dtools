Drupal project page: http://drupal.org/project/dtools
GitHub project page: https://github.com/kenorb/dtools

DESCRIPTION
  DTools (Diagnostic Tools) is a package of very useful diagnostics modules for Drupal 6.x. It contain following modules:

  WSOD

  Got WSOD (White Screen of Death)? You don't know why? You are sick, because you've got lot of modules and you can't lost your time to disable them each by each to check what's wrong and at the end the reason is because of some cache? This module is for you. You will ask: But how I can enable it, if I've got still WSOD? Simply go to: /sites/all/modules/dtools/wsod/wsod_emergency.php (update your path to correct one). It's secure, if there is no wsod detected, this script will not print any technical info. You can use 'q' argument to test different paths. Read README.txt how to use it.

  (Example usage: http://mysite/sites/all/modules/dtoosl/wsod_emergency.php?cmd=debug&q=us...)
  Available variables:
      q - change the path (default: node)
      cmd - execute internal command
        Available commands:
          phpinfo - show PHP Info page
          debug - enable trace debugger
      dcmd - execute internal command after Drupal bootstrap
        module_list - list of loaded all Drupal modules

  Drupal WSOD issues:
  Drupal WSOD issues which has 'won't fix' status:
#375468: silent WSOD on theme() exit when theme callback doesn't exist

  BENCH_CHART

  It will shows you how much time your Drupal application spend on specified hooks. Its perfect when you want to optimize your website or there is some problem with specified module and you don't know which one. Example charts: http://drupal.org/node/415748 Known issues with Drupal stability: #222073: Update Status causing Drupal to run very slowly Read more about fixing WSOD manually and read about common Drupal WSODs issues: http://drupal.org/node/482956 Recent questions: #417202: is it for using on live site or not?

Dependencies:
  http://drupal.org/project/charts

