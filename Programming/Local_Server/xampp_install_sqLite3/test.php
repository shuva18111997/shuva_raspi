<?php
  $db = new SQLite3('phpdb.db');

  if ($db) {
    $db->query("CREATE TABLE dogbreeds (Name VARCHAR(255), MaxAge INT);");
    $db->query("INSERT INTO dogbreeds VALUES ('Doberman', 15)");
    $result = $db->query("SELECT Name FROM dogbreeds");
    var_dump($result->fetchArray(SQLITE3_ASSOC));
  } else {
    print "Connection to database failed!\n";
  }
  
  //Link is--> https://stackoverflow.com/questions/33940419/how-to-configure-sqlite3-for-php-5-6-14-on-apache-2-4-windows-7
/*
Add this Lines to location :- C:\xampp\php\php.ini

extension=php_pdo_sqlite.dll
extension=php_sqlite3.dll
sqlite3.extension_dir = "C:\xampp\php\ext"

*/
?>