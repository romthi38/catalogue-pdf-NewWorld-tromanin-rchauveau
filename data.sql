INSERT INTO ptsDeVente (no,libelle,activite,nom,prenom,tel,rue1,cp,ville) VALUES
(1,"Paysans bio","epicerie","borel","gregoire","0492687514","10 boulevard Pompidou","05000","Gap"),
(2,"l’eau vive","supermarche","durand","mauricette","0492154867","10 avenue d emb
run","05000","Gap"),
(3,"Leclerc","supermarche","leclerc","edouard","0492515168","8 Z.I Tokoro","05000","Gap"),
(4,"fruits et legumes embrunais","marche","lagrange","georgette","0492446328","5 place victor hugo","05200","Embrun"),
(5,"au bon panier","boucherie","lagneau","jean","0492484897","26 rue du pin","05100","Briançon");



insert into utilisateur values
(1,"romanin","thibault","tromanin","rue1","rue2","05000","gap","@gmail.com","0495632541"),
(2,"chauveau","rémi","rchauveau","rue1","rue2","05000","gap","@gmail.com","0495632541"),
(3,"bouffier","pierre","tromanin","rue1","rue2","05000","gap","@gmail.com","0495632541");

INSERT INTO surType VALUES
(1,'Fruit'),
(2,'Legume'),
(3,'Viande'),
(4,'Poisson');

INSERT INTO typeP VALUES 
(1,'Pomme',1),
(2,'Poire',1),
(3,'Fraise',1),
(4,'Courgette',2),
(5,'Citrouille',2),
(6,'Tomate',2),
(7,'Viande rouge',3),
(8,'Viande blanche',3),
(9,'Ocean',4),
(10,'Riviere',4);


INSERT INTO produit VALUES 
(1,'golden',1),
(2,'Fuji',1),
(3,'Conference',2),
(4,'Williams',2),
(5,'Gariguette',3),
(6,'Reine des vallées',3),
(7,'Papaw',4),
(8,'Reine de Naples',4),
(9,'Angelique',5),
(10,'Atantic Giant',5),
(11,'Cerise',6),
(12,'Coeur de boeuf',6),
(13,'Boeuf',7),
(14,'Canard',7),
(15,'Dinde',8),
(16,'Anguille',9),
(17,'Thon',10);


INSERT INTO QAO VALUES
(1,5),
(1,4),
(2,1),
(2,3),
(3,2);

INSERT INTO lot VALUES
(3,48,2,"kilo","industrielle",'2015-10-01',12,15,1),
(2,10,2,"kilo","industrielle",'2015-09-27',8,16,1),
(1,20,2,"kilo","bio",'2015-10-01',20,17,1),
(4,150,2,"kilo","bio",'2015-10-01',20,1,1),
(5,150,1,"kilo","bio",'2015-10-01',20,3,1),
(6,150,2,"kilo","bio",'2015-10-02',17,4,1),
(7,30,2,"kilo","bio",'2015-09-30',10,5,1),
(8,30,2,"kilo","bio",'2015-09-30',10,6,1),
(9,8,4,"unite","bio",'2015-09-28',6,7,1),
(10,10,4,"unite","bio",'2015-09-27',7,8,1),
(11,15,3,"unite","bio",'2015-09-26',7,9,1),
(12,10,4,"unite","bio",'2015-10-01',7,10,1),
(13,35,2,"kilo","bio",'2015-09-25',10,11,1),
(14,15,2,"kilo","bio",'2015-10-01',14,12,1),
(15,45,2,"kilo","industrielle",'2015-10-03',10,13,1),
(16,20,2,"kilo","industrielle",'2015-10-02',7,14,1),
(17,20,5,"kilo","industrielle",'2015-10-02',7,15,1),
(18,20,2,"kilo","industrielle",'2015-10-02',7,16,1),
(19,20,2,"kilo","industrielle",'2015-10-02',7,17,1);

INSERT INTO proposerA VALUES
(1,1),
(1,2),
(1,3),
(1,6),
(1,7),
(1,9),
(1,15),
(1,16),
(2,2),
(2,3),
(2,7),
(2,5),
(2,9),
(2,12),
(2,16),
(3,2),
(3,1),
(3,5),
(3,8),
(3,11),
(3,10),
(4,1),
(4,2),
(4,3),
(4,6),
(4,14),
(4,13),
(4,4),
(4,8),
(5,16),
(5,17);