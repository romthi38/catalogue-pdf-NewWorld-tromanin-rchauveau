#include <QCoreApplication>
#include <QSqlDatabase>
#include <iostream>
#include <QPrinter>
#include <QPainter>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Connexion à la base de donnée
    QSqlDatabase * baseBornes;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseBornes = new QSqlDatabase(db);
    baseBornes->setHostName("172.16.63.111");
    baseBornes->setUserName("tromanin");
    baseBornes->setDatabaseName("dbtromaninNewWorld");
    baseBornes->setPassword("PPhdu14Zer");
    baseBornes->open();

    cout<<"Generation du catalogue..."<<endl;

    QPrinter printer;
    printer.setOutputFileName("catalogueNW.pdf");//nom du pdf
    printer.setOutputFormat(QPrinter::PdfFormat); //format du pdf







    return a.exec();
}
