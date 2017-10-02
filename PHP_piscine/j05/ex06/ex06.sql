SELECT title, summary FROM film
WHERE INSTR(summary, 'vincent')
ORDER BY id_film;