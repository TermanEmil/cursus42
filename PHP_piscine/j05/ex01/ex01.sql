CREATE TABLE ft_table (
	id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
	login VARCHAR(9) NOT NULL DEFAULT 'toto',
	groupe ENUM('staff', 'student', 'other') NOT NULL,
	creation_date DATE NOT NULL
);