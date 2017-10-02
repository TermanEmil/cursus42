mysql> show tables;
+----------------------+
| Tables_in_db_eterman |
+----------------------+
| abonnement           |
| distrib              |
| fiche_personne       |
| film                 |
| genre                |
| grille_programme     |
| historique_membre    |
| job                  |
| membre               |
| personnel            |
| reduction            |
| salle                |
+----------------------+

mysql> describe fiche_personne;
+----------------+--------------+------+-----+---------+-------+
| Field          | Type         | Null | Key | Default | Extra |
+----------------+--------------+------+-----+---------+-------+
| id_perso       | int(11)      | NO   | PRI | NULL    |       |
| nom            | varchar(255) | NO   |     | NULL    |       |
| prenom         | varchar(255) | NO   |     | NULL    |       |
| date_naissance | datetime     | NO   |     | NULL    |       |
| email          | varchar(255) | YES  |     | NULL    |       |
| adresse        | varchar(255) | YES  |     | NULL    |       |
| cpostal        | varchar(255) | YES  |     | NULL    |       |
| ville          | varchar(255) | YES  |     | NULL    |       |
| pays           | varchar(255) | YES  |     | NULL    |       |
+----------------+--------------+------+-----+---------+-------+

mysql> describe abonnement;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| id_abo    | int(11)      | NO   | PRI | NULL    |       |
| nom       | varchar(255) | NO   |     | NULL    |       |
| resum     | varchar(255) | NO   |     | NULL    |       |
| prix      | int(11)      | NO   |     | NULL    |       |
| duree_abo | tinyint(4)   | NO   |     | NULL    |       |
+-----------+--------------+------+-----+---------+-------+

mysql> describe membre;
+-------------------+----------+------+-----+---------+-------+
| Field             | Type     | Null | Key | Default | Extra |
+-------------------+----------+------+-----+---------+-------+
| id_membre         | int(11)  | NO   | PRI | NULL    |       |
| id_fiche_perso    | int(11)  | NO   |     | NULL    |       |
| id_abo            | int(11)  | YES  | MUL | NULL    |       |
| date_abo          | datetime | YES  |     | NULL    |       |
| id_dernier_film   | int(11)  | NO   |     | NULL    |       |
| date_dernier_film | datetime | YES  |     | NULL    |       |
| date_inscription  | datetime | YES  |     | NULL    |       |
+-------------------+----------+------+-----+---------+-------+

mysql> describe salle;
+--------------+--------------+------+-----+---------+-------+
| Field        | Type         | Null | Key | Default | Extra |
+--------------+--------------+------+-----+---------+-------+
| id_salle     | int(11)      | NO   | PRI | NULL    |       |
| numero_salle | tinyint(4)   | NO   |     | NULL    |       |
| nom_salle    | varchar(255) | NO   |     | NULL    |       |
| etage_salle  | int(11)      | NO   |     | NULL    |       |
| nbr_siege    | int(11)      | NO   |     | NULL    |       |
+--------------+--------------+------+-----+---------+-------+

mysql> describe distrib;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| id_distrib | int(11)      | NO   | PRI | NULL    |       |
| nom        | varchar(255) | NO   |     | NULL    |       |
| telephone  | varchar(255) | NO   |     | NULL    |       |
| adresse    | varchar(255) | YES  |     | NULL    |       |
| cpostal    | varchar(255) | YES  |     | NULL    |       |
| ville      | varchar(255) | YES  |     | NULL    |       |
| pays       | varchar(255) | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+

mysql> describe film;
+--------------------+--------------+------+-----+---------+-------+
| Field              | Type         | Null | Key | Default | Extra |
+--------------------+--------------+------+-----+---------+-------+
| id_film            | int(11)      | NO   | PRI | NULL    |       |
| id_genre           | tinyint(4)   | YES  | MUL | NULL    |       |
| id_distrib         | int(11)      | YES  | MUL | NULL    |       |
| titre              | varchar(255) | NO   |     | NULL    |       |
| resum              | varchar(255) | NO   |     | NULL    |       |
| date_debut_affiche | date         | NO   |     | NULL    |       |
| date_fin_affiche   | date         | NO   |     | NULL    |       |
| duree_min          | int(11)      | NO   |     | NULL    |       |
| annee_prod         | int(11)      | YES  |     | NULL    |       |
+--------------------+--------------+------+-----+---------+-------+

mysql> describe grille_programme;
+---------------------------+----------+------+-----+---------+-------+
| Field                     | Type     | Null | Key | Default | Extra |
+---------------------------+----------+------+-----+---------+-------+
| id_film                   | int(11)  | NO   |     | NULL    |       |
| id_salle                  | int(11)  | NO   |     | NULL    |       |
| id_fiche_perso_ouvreur    | int(11)  | NO   |     | NULL    |       |
| id_fiche_perso_technicien | int(11)  | NO   |     | NULL    |       |
| id_fiche_perso_menage     | int(11)  | NO   |     | NULL    |       |
| debut_sceance             | datetime | NO   |     | NULL    |       |
| fin_sceance               | datetime | NO   |     | NULL    |       |
+---------------------------+----------+------+-----+---------+-------+

mysql> describe historique_membre;
+-----------+----------+------+-----+---------+-------+
| Field     | Type     | Null | Key | Default | Extra |
+-----------+----------+------+-----+---------+-------+
| id_membre | int(11)  | NO   | MUL | NULL    |       |
| id_film   | int(11)  | NO   | MUL | NULL    |       |
| date      | datetime | NO   |     | NULL    |       |
+-----------+----------+------+-----+---------+-------+

