#include <QApplication>
#include <QSqlDatabase>
#include <iostream>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QPoint>
#include <QSqlQuery>
#include <QDebug>
#include <QTextCodec>

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

    cout<<"Génération du catalogue"<<endl;

    QApplication a(argc, argv);
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setOutputFileName("catalogueNW.pdf");
    QPainter painter;
    painter.begin(&printer);
    painter.setFont(QFont("Tahoma",25));

    painter.drawText(2500,2000,"Catalogue New World");
    painter.end();
    painter.begin(&printer);
    QSqlQuery queryPdv;
    queryPdv.exec("SELECT no, libelle, activite, nom, prenom, tel, rue1, cp, ville FROM ptsDeVente");
    int horizontale = 150;
    int verticale = 3500;

    while(queryPdv.next())
    {
        painter.setPen(QColor(85,78,78,255));
        painter.setFont(QFont("Tahoma",8));
        QString leNo = queryPdv.value(0).toString();
        painter.drawText(horizontale,1600,"N. " + leNo);
        QString leLib = queryPdv.value(1).toString();
        painter.drawText(horizontale,1750,leLib);
        QString act = queryPdv.value(2).toString();
        painter.drawText(horizontale,1900,act);
        QString leNom = queryPdv.value(3).toString();
        QString lePrenom = queryPdv.value(4).toString();
        painter.drawText(horizontale,2050,leNom + " " + lePrenom);
        QString leTel = queryPdv.value(5).toString();
        painter.drawText(horizontale,2200,"Tel. " + leTel);
        QString laRue = queryPdv.value(6).toString();
        painter.drawText(horizontale,2350,laRue);
        QString leCP = queryPdv.value(7).toString();
        painter.drawText(horizontale,2500,leCP);
        QString laVille = queryPdv.value(8).toString();
        painter.drawText(horizontale,2650,laVille);
        horizontale = horizontale + 2000;
    }

    //les rayons
    QSqlQuery queryRayon;
    queryRayon.exec("select libelle, no from surType");
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
        queryTypeProduit.exec("Select libelle, no from typeP where noSurType =" + QString(noRayon));
        while(queryTypeProduit.next())
        {
            painter.setFont(QFont("Tahoma",11));
            painter.setPen(QColor(55,53,53,255));
            QString libTypeProduit = queryTypeProduit.value(0).toString();
            QString noTypeProduit = queryTypeProduit.value(1).toString();
            QImage img(libTypeProduit+".png");
            img.load(libTypeProduit+".png");
            painter.drawImage(QPoint(1000,verticale+100),img);
            painter.drawRect(700,verticale - 200,8100,900);
            painter.drawText(1000,verticale,libTypeProduit);
            verticale = verticale + 300;

            QSqlQuery queryProduit;
            queryProduit.exec("Select libelle, no from produit where noType =" + QString(noTypeProduit));
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

    painter.end();
    return 0;
}

