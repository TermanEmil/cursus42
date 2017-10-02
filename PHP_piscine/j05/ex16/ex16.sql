SELECT COUNT(DISTINCT id_film) AS 'films'
FROM historique_membre
WHERE historique_membre.date BETWEEN '2006-10-30 00:00:00' AND '2007-07-27 00:00:00' OR
	DATE_FORMAT(historique_membre.date, '%m-%d') = '12-24';