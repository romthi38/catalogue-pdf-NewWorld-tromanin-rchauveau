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



    QApplication a(argc, argv);

    //client
    QSqlQuery queryUtilisateur;
    queryUtilisateur.exec("SELECT no from utilisateur");
    while(queryUtilisateur.next())//pour chaque clients
    {
        QString noClient = queryUtilisateur.value(0).toString();//on récupère le numéro du client

        QDate dateDuJour = QDate::currentDate();
        QString maDate = dateDuJour.toString("dd-MM-yyyy");
        QSqlQuery queryNoPdv;
        queryNoPdv.exec("SELECT ptsDeVente.no FROM ptsDeVente inner join QAO on ptsDeVente.no=QAO.noPtsDeVente inner join utilisateur on utilisateur.no=QAO.noUtilisateur where QAO.noUtilisateur="+noClient+" order by ptsDeVente.no");
        QString monNoPdv = maDate;
        while(queryNoPdv.next())
        {
            monNoPdv=monNoPdv+"_"+queryNoPdv.value(0).toString();
        }
        QPrinter printer(QPrinter::HighResolution);
        printer.setFullPage(QPrinter::A4);
        printer.setOutputFormat(QPrinter::NativeFormat);
        printer.setOutputFileName("catalogueNW_"+monNoPdv+".pdf");
        QPainter painter;
        painter.begin(&printer);
        painter.setFont(QFont("Tahoma",25));

        painter.drawText(2500,2000,"Catalogue New World");
        painter.end();
        painter.begin(&printer);
        QSqlQuery queryPdv;
        queryPdv.exec("SELECT ptsDeVente.no, ptsDeVente.libelle, ptsDeVente.activite, ptsDeVente.nom, ptsDeVente.prenom, ptsDeVente.tel, ptsDeVente.rue1, ptsDeVente.cp, ptsDeVente.ville FROM ptsDeVente inner join QAO on ptsDeVente.no=QAO.noPtsDeVente inner join utilisateur on utilisateur.no=QAO.noUtilisateur where QAO.noUtilisateur="+noClient+" order by ptsDeVente.no");
        int horizontale = 150;
        int verticale = 3500;

        painter.setPen(QColor(77,88,235,255));
        painter.setFont(QFont("Tahoma",13));
        painter.drawText(230,1600,"Point(s) de ventes");

        while(queryPdv.next())
        {
            painter.setPen(QColor(85,78,78,255));
            painter.setFont(QFont("Tahoma",8));
            QString leNo = queryPdv.value(0).toString();
            painter.drawText(horizontale,1800,"N. " + leNo);
            QString leLib = queryPdv.value(1).toString();
            painter.drawText(horizontale,1950,leLib);
            QString act = queryPdv.value(2).toString();
            painter.drawText(horizontale,2100,act);
            QString leNom = queryPdv.value(3).toString();
            QString lePrenom = queryPdv.value(4).toString();
            painter.drawText(horizontale,2250,leNom + " " + lePrenom);
            QString leTel = queryPdv.value(5).toString();
            painter.drawText(horizontale,2400,"Tel. " + leTel);
            QString laRue = queryPdv.value(6).toString();
            painter.drawText(horizontale,2550,laRue);
            QString leCP = queryPdv.value(7).toString();
            painter.drawText(horizontale,2700,leCP);
            QString laVille = queryPdv.value(8).toString();
            painter.drawText(horizontale,2850,laVille);
            horizontale = horizontale + 2000;
        }

        //les rayons
        QSqlQuery queryRayon;
        queryRayon.exec("select distinct surType.libelle, surType.no from surType inner join typeP on surType.no=typeP.noSurType inner join produit on typeP.no=produit.noType inner join lot on produit.no=lot.noProduit inner join proposerA on lot.no=proposerA.noLot inner join ptsDeVente on ptsDeVente.no=proposerA.noPointDeVente inner join QAO on ptsDeVente.no=QAO.noPtsDeVente inner join utilisateur on QAO.noUtilisateur=utilisateur.no  where utilisateur.no="+noClient);
        while(queryRayon.next())
        {
            painter.setPen(QColor(77,88,235,255));
            painter.setFont(QFont("Tahoma",14));
            QString lib = queryRayon.value(0).toString();
            QString noRayon = queryRayon.value(1).toString();
            QString quantiteProduit = "Qté";
            QString prixProduit = "Prix";
            QString modeProductionProduit = "Production";
            QString dateRecolteProduite = "Date récolte";
            QString joursDeConservationProduit = "Conservation";
            painter.drawText(400,verticale,"Rayon : "+lib);
            verticale = verticale + 300;
            painter.setFont(QFont("Tahoma",8));
            painter.drawText(4230,verticale,quantiteProduit);
            painter.drawText(4850,verticale,prixProduit);
            painter.drawText(5780,verticale,modeProductionProduit);
            painter.drawText(6800,verticale,dateRecolteProduite);
            painter.drawText(7800,verticale,joursDeConservationProduit);

            //type de produit
            QSqlQuery queryTypeProduit;
            //queryTypeProduit.exec("Select libelle, no from typeP where noSurType =" + QString(noRayon));
            queryTypeProduit.exec("Select distinct typeP.libelle, typeP.no from typeP inner join produit on typeP.no=produit.noType inner join lot on produit.no=lot.noProduit inner join proposerA on lot.no=proposerA.noLot inner join ptsDeVente on ptsDeVente.no=proposerA.noPointDeVente inner join QAO on ptsDeVente.no=QAO.noPtsDeVente inner join utilisateur on QAO.noUtilisateur=utilisateur.no  where utilisateur.no="+noClient+" and noSurType ="+QString(noRayon));
            while(queryTypeProduit.next())
            {
                painter.setFont(QFont("Tahoma",11));
                painter.setPen(QColor(55,53,53,255));
                QString libTypeProduit = queryTypeProduit.value(0).toString();
                QString noTypeProduit = queryTypeProduit.value(1).toString();
                QImage img(libTypeProduit+".png");
                img = img.scaledToHeight(500);
                //img.load(libTypeProduit+".png");
                painter.drawImage(QPoint(1000,verticale+100),img);
                painter.drawRect(700,verticale - 200,8100,900);
                painter.drawText(1000,verticale,libTypeProduit);
                verticale = verticale + 300;

                QSqlQuery queryProduit;
                queryProduit.exec("Select libelle, no from produit where noType =" + QString(noTypeProduit));
                //queryTypeProduit.exec("Select distinct produit.libelle, produit.no from produit inner join lot on produit.no=lot.noProduit inner join proposerA on lot.no=proposerA.noLot inner join ptsDeVente on ptsDeVente.no=proposerA.noPointDeVente inner join QAO on ptsDeVente.no=QAO.noPtsDeVente inner join utilisateur on QAO.noUtilisateur=utilisateur.no  where utilisateur.no="+noClient+" and noType ="+QString(noTypeProduit));
                while(queryProduit.next())
                {
                    painter.setFont(QFont("Tahoma",11));
                    QString libProduit = queryProduit.value(0).toString();
                    QString noProduit = queryProduit.value(1).toString();
                    painter.drawText(2200,verticale,libProduit);
                    QSqlQuery queryLot("Select qte, prixUnitaire, unite, modeDeProd, dateDeRecolte, nbrJoursDeConservation from lot where no="+QString(noProduit));
                    while(queryLot.next())
                    {
                        QString quantiteLot = queryLot.value(0).toString();
                        QString prixLot = queryLot.value(1).toString();
                        QString uniteLot = queryLot.value(2).toString();
                        QString modeDeProdLot = queryLot.value(3).toString();
                        QString dateDeRecolteLot = queryLot.value(4).toString();
                        QString nbrJoursDeConservationLot = queryLot.value(5).toString();
                        painter.setFont(QFont("Tahoma",9));
                        painter.drawText(4200,verticale,quantiteLot);
                        painter.drawText(4800,verticale,prixLot+"€ / "+uniteLot);
                        painter.drawText(5800,verticale,modeDeProdLot);
                        painter.drawText(6800,verticale,dateDeRecolteLot);
                        painter.drawText(8000,verticale,nbrJoursDeConservationLot+" jour(s)");
                    }

                    verticale = verticale + 300;
                }
            }
            verticale = verticale + 200;
        }
        QImage img("logo.png");
        img.load("logo.png");
        painter.drawImage(QPoint(0,100),img);
        painter.setPen(QColor(0,0,0,255));
        painter.drawLine(0,1300,9100,1300);
        painter.drawLine(0,3100,9100,3100);
        painter.drawLine(0,12500,9100,12500);



        painter.end();
    }
    return 0;
}
