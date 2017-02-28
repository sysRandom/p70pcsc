--TEST--
Check for p70pcsc presence
--SKIPIF--
<?php if (!extension_loaded("p70pcsc")) print "skip"; ?>
--FILE--
<?php 
echo "p70pcsc extension is available";
/*
	you can add regression tests for your extension here

  the output of your test code has to be equal to the
  text in the --EXPECT-- section below for the tests
  to pass, differences between the output and the
  expected text are interpreted as failure

	see php7/README.TESTING for further information on
  writing regression tests
*/
?>
--EXPECT--
p70pcsc extension is available
