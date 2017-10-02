INSERT INTO ft_table (groupe, login, creation_date)
	SELECT 'other', last_name, LEFT(birthdate, 10)
	FROM user_card
	WHERE INSTR(last_name, 'a') AND CHAR_LENGTH(last_name) < 9
	ORDER BY last_name
	LIMIT 10;