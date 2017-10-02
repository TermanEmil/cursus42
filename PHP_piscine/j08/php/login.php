<?php

require_once("{$_SERVER['DOCUMENT_ROOT']}/classes.php");

if (!isset($_POST['submit_login']))
    exit(0);

session_start();

$_SESSION['sqlCon'] = new SqlConnection();
$_SESSION['sqlCon']->auth();