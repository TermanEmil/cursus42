SELECT UPPER(pers.nom) AS 'NOM', pers.prenom, ab.prix
FROM membre
INNER JOIN abonnement ab ON membre.id_abo = ab.id_abo
INNER JOIN fiche_personne pers ON membre.id_fiche_perso = pers.id_perso
WHERE ab.prix > 42;