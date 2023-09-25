<?php
$db = new SQLite3('myDB.db');

$results = $db->query('SELECT name FROM myTable');
while ($row = $results->fetchArray()) {
    var_dump($row);
}
?>