#include <QApplication>
#include <QSqlDatabase>
#include <iostream>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QPoint>
#include <QSqlQuery>
#include <QDebug>
#include <QTextCodec>
#include <QDate>

using namespace std;

void createfooter(QPainter *painter, QDate *dateDuJour, int cptPage){
    painter->setPen(QColor(0,0,0,255));
    painter->setFont(QFont("Tahoma",10));
    QString dateFooter = dateDuJour->toString("'Catalogue généré le' dd/MM/yyyy");
    QString copyright = "© Copyright New World 2016 - Thibault ROMANIN & Rémi CHAUVEAU";
    painter->drawText(150,12800,dateFooter);
    painter->drawText(150,13100,copyright);
    painter->drawText(9000,13100,QString::number(cptPage));
    painter->drawLine(0,12500,9100,12500);
}

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // Connexion à la base de donnée
    QSqlDatabase * baseBornes;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseBornes = new QSqlDatabase(db);
    baseBornes->setHostName("172.16.63.111");
    baseBornes->setUserName("tromanin");
    baseBornes->setDatabaseName("dbtromaninNewWorld");
    baseBornes->setPassword("PPhdu14Zer");
    baseBornes->open();

    cout<<"***************************"<<endl;
    cout<<"| Génération du catalogue |"<<endl;
    cout<<"***************************"<<endl;

    // TODO : afficher les points de vente où le lot est disponible

    QApplication a(argc, argv);
    
    // Pour chaque utilisateur
    QSqlQuery queryUtilisateur;
    queryUtilisateur.exec("SELECT usId FROM Utilisateur WHERE usTypeUtilisateur = 2");
    while(queryUtilisateur.next())//pour chaque clients
    {
        // On récupère l'id de l'utilisateur
        QString idUtilisateur = queryUtilisateur.value(0).toString();
        qDebug() << "Id utilisateur : " + idUtilisateur;

        // Date du jour pour le titre du fichier pdf
        QDate dateDuJour = QDate::currentDate();
        QString maDate = dateDuJour.toString("dd-MM-yyyy");

        // On récupère l'id du point de vente pour le titre du fichier pdf
        QSqlQuery queryIdPdv;
        queryIdPdv.exec("SELECT PointVente.pvId FROM PointVente INNER JOIN QuiAcheteOu ON PointVente.pvId = QuiAcheteOu.idPointVente INNER JOIN Utilisateur ON Utilisateur.usId = QuiAcheteOu.idUtilisateur WHERE QuiAcheteOu.idUtilisateur=" + idUtilisateur + " ORDER BY PointVente.pvId");

        // On ajoute au titre du fichier pdf les numéros de tous les points de ventes qu'un utilisateur a choisi
        QString nomFichierPdf = maDate;
        while(queryIdPdv.next())
        {
            nomFichierPdf += "_"+queryIdPdv.value(0).toString();
        }

        // Création du fichier
        QPrinter printer(QPrinter::HighResolution);
        printer.setFullPage(QPrinter::A4);
        printer.setOutputFormat(QPrinter::NativeFormat);
        printer.setOutputFileName("catalogueNW_"+nomFichierPdf+".pdf");

        // Création du painter
        QPainter painter;
        painter.begin(&printer);

        // Initialisation de variables
        int horizontale = 150;
        int verticale = 1800;
        int cptPage = 1;

        // Entête fichier pdf
        QImage img("logo.png");
        img.load("logo.png");
        painter.drawImage(QPoint(0,100),img);

        // Début des points de vente (changement police)
        painter.setPen(QColor(77,88,235,255));
        painter.setFont(QFont("Tahoma",13));
        painter.drawText(190,1600,"Point(s) de vente");

        // Footer
        createfooter(&painter,&dateDuJour,cptPage);
        painter.drawLine(0,1300,9100,1300);
        //painter.drawLine(0,3100,9100,3100);
        //painter.drawLine(9100,1300,9100,3100);

        // On sélectionne tous les points de ventes de l'utilisateur
        QSqlQuery queryPdv;
        queryPdv.exec("SELECT PointVente.pvId, PointVente.pvLibelle, PointVente.pvActivite, PointVente.pvNomResponsable, PointVente.pvPrenomResponsable, PointVente.pvTelResponsable, PointVente.pvAdresse1, Localite.locCP, Localite.locNomCommune, PointVente.pvEmailResponsable FROM PointVente INNER JOIN QuiAcheteOu ON PointVente.pvId = QuiAcheteOu.idPointVente INNER JOIN Localite ON Localite.locCodeInsee = PointVente.pvLocalite INNER JOIN Utilisateur ON Utilisateur.usId = QuiAcheteOu.idUtilisateur WHERE QuiAcheteOu.idUtilisateur = " + idUtilisateur + " ORDER BY PointVente.pvId");

        int numeroPdv = 1;
        while(queryPdv.next())
        {
            // Changement de la police d'écriture
            painter.setPen(QColor(85,78,78,255));
            painter.setFont(QFont("Tahoma",8));

            // Numéro du point de vente (c'est un compteur)
            QString leNo = QString::number(numeroPdv);

            // Retour à la ligne
            verticale -= 1500;
            if(numeroPdv % 4 == 1){
                verticale += 1500;
                horizontale = 150;
                painter.drawLine(0,verticale + 1300,9100,verticale + 1300);
                painter.drawLine(9100,verticale - 500,9100,verticale + 1300);
            }else{
                horizontale += 2300;
            }

            // Affichage des points de vente
            painter.drawLine(horizontale - 150,verticale - 500,horizontale - 150 ,verticale + 1300);
            //painter.drawText(horizontale,verticale,"point de vente n°" + queryPdv.value(0).toString());
            painter.drawText(horizontale,verticale,"point de vente n°" + leNo);
            QString leLib = queryPdv.value(1).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,leLib);
            QString act = queryPdv.value(2).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,act);
            QString leNom = queryPdv.value(3).toString();
            QString lePrenom = queryPdv.value(4).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,leNom + " " + lePrenom);
            QString leTel = queryPdv.value(5).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,"Tel. " + leTel);
            QString leMail = queryPdv.value(9).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,leMail);
            QString laRue = queryPdv.value(6).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,laRue);
            QString leCP = queryPdv.value(7).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,leCP);
            QString laVille = queryPdv.value(8).toString();
            verticale+=150;
            painter.drawText(horizontale,verticale,laVille);
            verticale += 300;
            numeroPdv ++;
        } // Fin while queryPdv

        painter.drawLine(horizontale + 2150,verticale - 200,horizontale + 2150 ,verticale - 2000);

        verticale += 500;

        // Titre entre les points de vente et les rayons
        painter.setPen(QColor(0,0,0,255));
        painter.setFont(QFont("Tahoma",10));
        painter.drawText(2500,verticale-400,"Produits disponibles à l'achat dans ces points de ventes :");

        // On sélectionne tous les surtypes en fonction de l'id de l'utilisateur
        QSqlQuery querySurType;
        querySurType.exec("SELECT DISTINCT SurType.stLibelle, SurType.stId FROM SurType INNER JOIN TypeProduit ON SurType.stId = TypeProduit.tpSurType INNER JOIN Produit ON TypeProduit.tpId = Produit.prTypeProduit INNER JOIN Lot ON Produit.prId = Lot.lotProduit INNER JOIN QuoiVenduOu ON Lot.lotId = QuoiVenduOu.idLot INNER JOIN PointVente on PointVente.pvId = QuoiVenduOu.idPointVente INNER JOIN QuiAcheteOu ON PointVente.pvId = QuiAcheteOu.idPointVente INNER JOIN Utilisateur ON QuiAcheteOu.idUtilisateur = Utilisateur.usId  WHERE Utilisateur.usId =" + idUtilisateur +" ORDER BY SurType.stId");
        while(querySurType.next())
        {          
            // Ajout d'une nouvelle page
            if(verticale > 10000){
                printer.newPage();
                verticale = 200;
                cptPage ++;

                // Footer
                createfooter(&painter,&dateDuJour,cptPage);
                qDebug() << "nouvelle page (surtype) pour l'utilisateur " + idUtilisateur;
            }

            // Changement police d'écriture
            painter.setPen(QColor(77,88,235,255));
            painter.setFont(QFont("Tahoma",14));

            // Affichage des surtypes
            QString lib = querySurType.value(0).toString();
            painter.drawText(150,verticale,lib);
            QString idSurType = querySurType.value(1).toString();

            // Affichage des intitulés pour les informations sur le lot            
            painter.setFont(QFont("Tahoma",8));            
            painter.drawText(3900,verticale,"Quantité");
            painter.drawText(5000,verticale,"Prix Unitaire");
            painter.drawText(6000,verticale,"Production");
            painter.drawText(7500,verticale,"Récolté le");
            painter.drawText(8300,verticale,"Conservation");
            verticale = verticale + 300;

            // On sélectionne tous les types de produits en fonction de l'id de l'utilisateur et de l'id du surtype
            QSqlQuery queryTypeProduit;
            queryTypeProduit.exec("SELECT DISTINCT TypeProduit.tpLibelle, TypeProduit.tpId FROM TypeProduit INNER JOIN Produit on TypeProduit.tpId = Produit.prTypeProduit INNER JOIN Lot ON Produit.prId = Lot.lotProduit INNER JOIN QuoiVenduOu ON Lot.lotId = QuoiVenduOu.idLot INNER JOIN PointVente on PointVente.pvId = QuoiVenduOu.idPointVente INNER JOIN QuiAcheteOu ON PointVente.pvId = QuiAcheteOu.idPointVente INNER JOIN Utilisateur ON QuiAcheteOu.idUtilisateur = Utilisateur.usId WHERE Utilisateur.usId =" + idUtilisateur + " AND tpSurType =" + QString(idSurType));
            while(queryTypeProduit.next())
            {
                // Ajout d'une nouvelle page
                if(verticale > 12500){
                    printer.newPage();
                    verticale = 200;
                    cptPage ++;

                    // Footer
                    createfooter(&painter,&dateDuJour,cptPage);
                    qDebug() << "nouvelle page (typeproduit) pour l'utilisateur " + idUtilisateur;
                }

                // Trait en dessous du surtype
                painter.drawLine(0,verticale - 200,9100,verticale - 200);

                // Changement police d'écriture
                painter.setFont(QFont("Tahoma",11));
                painter.setPen(QColor(55,53,53,255));

                // Trait en dessous du surtype
                painter.drawLine(350,verticale + 80,3650,verticale + 80);
                painter.drawLine(3650,verticale + 80,3800,verticale - 200);
                painter.drawLine(350,verticale + 80,200,verticale - 200);

                // Affichage des types de produits
                QString libTypeProduit = queryTypeProduit.value(0).toString();
                QString idTypeProduit = queryTypeProduit.value(1).toString();
                painter.drawText(400,verticale,libTypeProduit);
                verticale = verticale + 300;                

                // On sélectionne tous les produits en fonction de l'id de l'utilisateur et de l'id du type de produit
                QSqlQuery queryProduit;
                queryProduit.exec("SELECT DISTINCT Produit.prLibelle, Produit.prId, count(Produit.prLibelle) FROM Produit INNER JOIN Lot ON Produit.prId = Lot.lotProduit INNER JOIN QuoiVenduOu ON Lot.lotId = QuoiVenduOu.idLot INNER JOIN PointVente on PointVente.pvId = QuoiVenduOu.idPointVente INNER JOIN QuiAcheteOu ON PointVente.pvId = QuiAcheteOu.idPointVente INNER JOIN Utilisateur ON QuiAcheteOu.idUtilisateur = Utilisateur.usId WHERE Utilisateur.usId=" + idUtilisateur + " AND prTypeProduit =" + QString(idTypeProduit));
                while(queryProduit.next())
                {
                    // Ajout d'une nouvelle page
                    if(verticale > 12500){
                        printer.newPage();
                        verticale = 200;
                        cptPage ++;

                        // Footer
                        createfooter(&painter,&dateDuJour,cptPage);
                        qDebug() << "nouvelle page (produit) pour l'utilisateur " + idUtilisateur;
                    }

                    // Image du produit
                    QImage img("Golden.jpg");
                    img = img.scaledToHeight(600);
                    painter.drawImage(QPoint(400,verticale - 150),img);

                    // Changement police d'écriture
                    painter.setFont(QFont("Tahoma",11));

                    // Affichage du libellé du produit
                    QString libProduit = queryProduit.value(0).toString();
                    QString idProduit = queryProduit.value(1).toString();
                    painter.drawText(1600,verticale,libProduit);

                    int nbLot = 1;

                    // On sélectionne les lots qui concernent chaque produit
                    QSqlQuery queryLot("SELECT lotQuantite, lotPrixUnitaire, Unite.libelle, ModeProduction.libelle, lotDateRecolte, lotDureeConservation FROM Lot INNER JOIN Unite ON Unite.id = Lot.lotUnite INNER JOIN ModeProduction ON ModeProduction.id = Lot.lotModeProduction WHERE lotProduit =" + QString(idProduit));
                    while(queryLot.next())
                    {                        
                        // Cpt lot
                        verticale += 300;

                        // Ajout d'une nouvelle page
                        if(verticale > 12500){
                            printer.newPage();
                            verticale = 200;
                            cptPage ++;

                            // Footer
                            createfooter(&painter,&dateDuJour,cptPage);
                            qDebug() << "nouvelle page (lot) pour l'utilisateur " + idUtilisateur;
                        }

                        // Changement police d'écriture
                        painter.setFont(QFont("Tahoma",9));

                        // Affichage des lots
                        QString quantiteLot = queryLot.value(0).toString();
                        QString prixLot = queryLot.value(1).toString();
                        QString uniteLot = queryLot.value(2).toString();
                        QString modeDeProdLot = queryLot.value(3).toString();
                        QString dateDeRecolteLot = queryLot.value(4).toString();
                        QString nbrJoursDeConservationLot = queryLot.value(5).toString();
                        painter.drawText(4000,verticale,quantiteLot + " " + uniteLot);
                        painter.drawText(5100,verticale,prixLot+" €");
                        painter.drawText(6000,verticale,modeDeProdLot);
                        painter.drawText(7500,verticale,dateDeRecolteLot);
                        painter.drawText(8500,verticale,nbrJoursDeConservationLot+" jour(s)");

                        nbLot++;
                    } // Fin While querylot
                    verticale += 400;
                }
            } // Fin while queryTypeProduit
            verticale += 200;
        } // Fin while querySurType
        painter.end();
    } // Fin while queryUtilisateur

    return 0;
}
