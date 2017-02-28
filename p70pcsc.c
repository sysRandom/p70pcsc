/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_p70pcsc.h"

ZEND_DECLARE_MODULE_GLOBALS(p70pcsc)

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(p70pcsc)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(p70pcsc)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(p70pcsc)
{
#if defined(COMPILE_DL_P70PCSC) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(p70pcsc)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(p70pcsc)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "p70pcsc support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ p70pcsc_functions[] */
const zend_function_entry p70pcsc_functions[] = {
	PHP_FE_END	/* Must be the last line in p70pcsc_functions[] */
};
/* }}} */

/* {{{ p70pcsc_module_entry
 */
zend_module_entry p70pcsc_module_entry = {
	STANDARD_MODULE_HEADER,
	"p70pcsc",
	p70pcsc_functions,
	PHP_MINIT(p70pcsc),
	PHP_MSHUTDOWN(p70pcsc),
	PHP_RINIT(p70pcsc),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(p70pcsc),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(p70pcsc),
	PHP_P70PCSC_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_P70PCSC
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(p70pcsc)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
