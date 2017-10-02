SELECT title, summary
FROM film
WHERE INSTR(title, "42") OR INSTR(summary, "42")
ORDER BY duration;