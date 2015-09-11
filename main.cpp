#include <QCoreApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    // Connexion à la base de données
    QSqlDatabase * baseBornes;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseBornes = new QSqlDatabase(db);
    baseBornes->setHostName("localhost");
    baseBornes->setUserName("root");
    baseBornes->setDatabaseName("backOfficeNW");
    baseBornes->setPassword("passf005");
    baseBornes->open();

    return a.exec();
}
