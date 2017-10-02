<?php
const BR = "<br />\n";

class SqlConnection
{
    public          $_conn;
 
    public static   $verbose = FALSE;
 
    private         $_servername;
    private         $_dbport = 3306;
    private         $_username;
    private         $_database = 'db_space_game';
    
    /*
    ** Public
    */
    
    public function init_db()
    {
        $sql = 'CREATE DATABASE ' . $this->_database;
        
        $this->conn->query($sql);
        if ($this->error)
        {
            if (!preg_match('/exists/', $this->error))
                die('Failed to created database ' . $this->_database . ': ' . $this->error . BR);
        }
        else if (self::$verbose)
            echo 'Created database ' . $this->_database . BR;
        
        $sql = 'USE ' . $this->_database;
        if ($this->conn->query($sql) === FALSE)
            die('Failed to use database: ' . $this->_database . BR);
        
        $this->_init_tables();
    }
    
    function        auth()//$username, $passwd)
    {
        $sql = "SHOW DATABASES";
        print_r($this->conn->query($sql)->fetch_array(MYSQLI_NUM));
    }
    
    /*
    ** Special
    */
    
    public function __construct()
    {
        $this->servername = getenv('IP');
        $this->username = getenv('C9_USER');
        $this->_connect();
        
        if (self::$verbose)
            echo 'SqlConnection instance constructed' . BR;
    }
    
    public function __destruct()
    {
        // $this->conn->close();
        if (self::$verbose)
            echo 'SqlConnection instance destructed' . BR;
    }
    
    /*
    ** Private
    */
    
    private function        _connect()
    {
        $this->conn = new mysqli($this->servername, $this->username, "");
        if ($this->conn->connect_error)
            die("Connection failed: " . $this->conn->connect_error);
        if (self::$verbose)
            echo 'Successfully connected' . BR;
    }
    
    private function        _init_tables()
    {
        $sql = '
            CREATE TABLE ship (
            	ship_id INT AUTO_INCREMENT,
            	x INT DEFAULT 0,
            	y INT DEFAULT 0,
            	hp DOUBLE DEFAULT 100,
            	lvl INT DEFAULT 1,
            	PRIMARY KEY (ship_id)
            );';

        
        $this->conn->query($sql);
        if ($this->conn->errno)
        {
            if (!preg_match('/already exists/', $this->conn->error))
                die('Creating table: ' . $this->conn->error . BR);
            
        }
        else if (self::$verbose)
            echo 'Table ship created' . BR;
        
        $sql = '
            CREATE TABLE player (
            	player_id INT AUTO_INCREMENT,
            	ship_id INT DEFAULT NULL,
            	PRIMARY KEY (player_id),
            	FOREIGN KEY (ship_id) REFERENCES ship(ship_id)
            	ON DELETE CASCADE
            );';
        
        $this->conn->query($sql);
        if ($this->conn->errno)
        {
            if (!preg_match('/already exists/', $this->conn->error))
                die('Creating table: ' . $this->conn->error . BR);
            
        }
        else if (self::$verbose)
            echo 'Table player created' . BR;
            
        $sql = "
            CREATE TABLE account (
            	account_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
            	login VARCHAR(20) NOT NULL DEFAULT 'guest',
            	passwd VARCHAR(150) NOT NULL,
            	permission ENUM('admin', 'simple') DEFAULT 'simple',
            	player_id INT,
            	FOREIGN KEY (player_id) REFERENCES player(player_id)
            	ON DELETE CASCADE
            );";
        
        $this->conn->query($sql);
        if ($this->conn->errno)
        {
            if (!preg_match('/already exists/', $this->conn->error))
                die('Creating table: ' . $this->conn->error . BR);
            
        }
        else if (self::$verbose)
            echo 'Table account created' . BR;
    }
    
}

// SqlConnection::$verbose = TRUE;

// $conn = new SqlConnection();
// $conn->init_db();