SELECT nom, prenom
FROM fiche_personne
WHERE INSTR(nom, '-')  OR INSTR(TRIM(nom), ' ') OR
	INSTR(prenom, '-') OR INSTR(TRIM(prenom), ' ')
ORDER BY
	nom ASC, prenom ASC;