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
    int v1 = 150;
    int v2 = 500;
    while(query.next())
    {
        QString test = query.value(0).toString();
        v2 = v2 + 500;
        painter.drawText(v1,v2,test);
    }*/

    QSqlQuery queryPdv;
    queryPdv.exec("SELECT no, libelle, activite, nom, prenom, tel, rue1, cp, ville FROM ptsDeVente where no = 1");
    while(queryPdv.next())
    {
        //int leNo = queryPdv.value(0).toInt();
        //painter.drawText(100,150,leNo);
        QString leLib = queryPdv.value(1).toString();
        painter.drawText(150,150,leLib);
        QString act = queryPdv.value(2).toString();
        painter.drawText(200,150,act);
        QString leNom = queryPdv.value(3).toString();
        painter.drawText(250,150,leNom);
        QString lePrenom = queryPdv.value(4).toString();
        painter.drawText(300,150,lePrenom);
        QString leTel = queryPdv.value(5).toString();
        painter.drawText(350,150,leTel);
        QString laRue = queryPdv.value(6).toString();
        painter.drawText(400,150,laRue);
        QString leCP = queryPdv.value(7).toString();
        painter.drawText(450,150,leCP);
        QString laVille = queryPdv.value(8).toString();
        painter.drawText(500,150,laVille);
    }
    painter.drawText(2500,250,"Catalogue New World");



    painter.end();

    return 0;
}
