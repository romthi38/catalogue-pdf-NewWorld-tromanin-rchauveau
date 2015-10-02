-- Suppression des tables
drop table if exists proposerA;
drop table if exists lot;
drop table if exists ptsDeVente;
drop table if exists utilisateur;
drop table if exists produit;
drop table if exists typeP;
drop table if exists surType;
drop table if exists QAO;

-- Création de la table typeP
create table typeP(
	no smallint,
	libelle varchar(50),
	noSurType smallint,
	primary key(no)
)engine=innodb charset=UTF8;

-- Création de la table surType
create table surType(
	no smallint,
	libelle varchar(50),
	primary key(no)
)engine=innodb charset=UTF8;


-- Création de la table produit
create table produit(
	no smallint,
	libelle varchar(50),
	noType smallint,
	primary key(no)
)engine=innodb charset=UTF8;

-- Création de la table lot
create table lot(
	no smallint,
	qte smallint,
	prixUnitaire float,
	unite varchar(20),
	modeDeProd varchar(20),
	dateDeRecolte date,
	nbrJoursDeConservation smallint,
	noProduit smallint,
	noUtilisateur smallint,
	primary key(no)
)engine=innodb charset=UTF8;

-- Création de la table proposerA
create table proposerA(
	noPointDeVente smallint,
	noLot smallint,
	primary key (noPointDeVente,noLot)
)engine=innodb charset=UTF8;



-- Création de la table utilisateur
create table utilisateur(
	no smallint,
	nom varchar(60),
	prenom varchar(60),
	pseudo varchar(30),
	rue1 varchar(60),
	rue2 varchar(60),
	cp varchar(5),
	ville varchar(50),	
	email varchar(60),
	tel varchar(20),
	primary key(no)
)engine=innodb charset=UTF8;


-- Création de la table ptsDeVente
create table ptsDeVente(
	no smallint,
	libelle varchar(50),
	activite varchar(50),
	nom varchar(50),
	prenom varchar(50),
	tel varchar(20),
	email varchar(75),
	rue1 varchar(50),
	rue2 varchar(50),
	cp varchar(5),
	ville varchar(60),
	primary key (no)
)engine=innodb charset=UTF8;



-- Création de la table QAO (qui achète où)
create table QAO(
	noUtilisateur smallint,
	noPtsDeVente smallint,
	primary key (noUtilisateur, noPtsDeVente)
)engine=innodb charset=UTF8;


-- Liaisons des tables
ALTER TABLE proposerA
	add foreign key(noLot) references lot(no),
	add foreign key(noPointDeVente) references ptsDeVente(no);

ALTER TABLE lot
	add foreign key (noUtilisateur) references utilisateur(no);

ALTER TABLE lot
	add foreign key (noProduit) references produit(no);

ALTER TABLE produit
	add foreign key (noType) references typeP(no);

ALTER TABLE typeP
	add foreign key (noSurType) references surType(no);

ALTER TABLE QAO
	add foreign key (noUtilisateur) references utilisateur(no),
	add foreign key (noPtsDeVente) references ptsDeVente(no);
