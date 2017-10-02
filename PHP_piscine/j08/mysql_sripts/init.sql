CREATE DATABASE db_space_game;
USE db_space_game;

CREATE TABLE ship (
	ship_id INT AUTO_INCREMENT,
	x INT DEFAULT 0,
	y INT DEFAULT 0,
	hp DOUBLE DEFAULT 100,
	lvl INT DEFAULT 1,
	PRIMARY KEY (ship_id)
);

CREATE TABLE player (
	player_id INT AUTO_INCREMENT,
	ship_id INT DEFAULT NULL,
	PRIMARY KEY (player_id),
	FOREIGN KEY (ship_id) REFERENCES ship(ship_id)
	ON DELETE CASCADE
);

CREATE TABLE account (
	account_id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
	login VARCHAR(20) NOT NULL DEFAULT 'guest',
	passwd VARCHAR(150) NOT NULL,
	permission ENUM('admin', 'simple') DEFAULT 'simple',
	player_id INT,
	FOREIGN KEY (player_id) REFERENCES player(player_id)
	ON DELETE CASCADE
);

