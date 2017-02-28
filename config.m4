dnl $Id$
dnl config.m4 for extension p70pcsc

PHP_ARG_ENABLE(p70pcsc, PC/SC Smart Card support for PHP,
[  --enable-p70pcsc           Enable PC/SC Smart Card support])

if test "$PHP_P70PCSC" != "no"; then
  if test -r $PHP_P70PCSC/include/PCSC/winscard.h; then
    PCSC_DIR=$PHP_P70PCSC
  else
    AC_MSG_CHECKING(for PC/SC in default path)
    for i in /usr/local /usr; do
      if test -r $i/include/PCSC/winscard.h; then
        PCSC_DIR=$i
        AC_MSG_RESULT([winscard found in $i])
        break
      fi
    done
  fi

  if test -z "$PCSC_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the pcsc-lite distribution -
                    winscard.h should be in <pcsc-dir>/include/PCSC/])
  fi

  PHP_ADD_INCLUDE($P70PCSC_DIR/include/PCSC/)

  PHP_ADD_LIBRARY_WITH_PATH(pcsclite, "$PCSC_DIR/$PHP_LIBDIR", PCSC_SHARED_LIBADD)
  PHP_NEW_EXTENSION(p70pcsc, p70pcsc.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
  PHP_INSTALL_HEADERS([ext/p70pcsc], [php_p70pcsc.h])
  PHP_SUBST(P70PCSC_SHARED_LIBADD)
fi
