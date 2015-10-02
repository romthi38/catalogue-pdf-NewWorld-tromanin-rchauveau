#include <QApplication>
#include <QSqlDatabase>
#include <iostream>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QPoint>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{

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
    QPrinter printer(QPrinter::HighResolution); //create your QPrinter (don't need to be high resolution, anyway)
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setOutputFileName("catalogueNW.pdf");
    QPainter painter;
    painter.begin(&printer);
    painter.setFont(QFont("Tahoma",25));
    //painter.setPen(QColor(0, 0, 128, 128));

    /*QSqlQuery query;
    query.exec("SELECT libelle, noType FROM produit");
    int horizontale1 = 150;
    int verticale1 = 500;
    while(query.next())
    {
        QString test = query.value(0).toString();
        verticale1 = verticale1 + 500;
        painter.drawText(horizontale1,verticale1,test);
    }*/


    painter.drawText(2500,2000,"Catalogue New World");
    painter.end();
    painter.begin(&printer);
    QSqlQuery queryPdv;
    queryPdv.exec("SELECT no, libelle, activite, nom, prenom, tel, rue1, cp, ville FROM ptsDeVente");
    int horizontale = 150;
    int verticale = 3000;

    while(queryPdv.next())
    {
        painter.setFont(QFont("Tahoma",8));
        QString leNo = queryPdv.value(0).toString();
        painter.drawText(horizontale,100,"N. " + leNo);
        QString leLib = queryPdv.value(1).toString();
        painter.drawText(horizontale,250,leLib);
        QString act = queryPdv.value(2).toString();
        painter.drawText(horizontale,400,act);
        QString leNom = queryPdv.value(3).toString();
        QString lePrenom = queryPdv.value(4).toString();
        painter.drawText(horizontale,550,leNom + " " + lePrenom);
        QString leTel = queryPdv.value(5).toString();
        painter.drawText(horizontale,700,"Tel. " + leTel);
        QString laRue = queryPdv.value(6).toString();
        painter.drawText(horizontale,850,laRue);
        QString leCP = queryPdv.value(7).toString();
        painter.drawText(horizontale,1000,leCP);
        QString laVille = queryPdv.value(8).toString();
        painter.drawText(horizontale,1150,laVille);
        horizontale = horizontale + 2000;

        painter.setFont(QFont("Tahoma",18));
        painter.drawText(250,verticale - 350,"Point de vente : "+leLib);

        //les rayons
        QSqlQuery queryRayon;
        queryRayon.exec("select libelle, no from surType");
        while(queryRayon.next())
        {

            painter.setFont(QFont("Tahoma",14));
            QString lib=queryRayon.value(0).toString();
            QString noRayon=queryRayon.value(1).toString();
            painter.drawText(400,verticale,"Rayon : "+lib);
            verticale = verticale + 300;

            //type de produit
            QSqlQuery queryTypeProduit;
            queryTypeProduit.exec("Select libelle from typeP where noSurType =" + QString(noRayon));
            while(queryTypeProduit.next())
            {
                painter.setFont(QFont("Tahoma",11));
                QString libTypeProduit=queryTypeProduit.value(0).toString();
                painter.drawText(1400,verticale,libTypeProduit);
                verticale = verticale + 300;
            }
        }
        verticale = verticale + 500;
    }
    painter.end();
    return 0;
}
