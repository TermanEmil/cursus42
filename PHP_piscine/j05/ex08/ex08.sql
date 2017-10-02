SELECT last_name, first_name, LEFT(birthdate, 10) AS 'birthdate'
FROM user_card
WHERE INSTR(birthdate, '1989')
ORDER BY last_name;