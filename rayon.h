/**
* @file rayon.h
* @brief Classe de Rayon
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:04:00
* @class Rayon
*/

#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlRecord>

class Rayon
{
private:
    // Numéro du rayon
    int noRayon;
    // Libelle du rayon
    QString libelleRayon;

public:
    // Constructeur
    Rayon(int no, QString lib);
    Rayon();

    // Retourne le libellé du rayon
    QString getLibelleRayon();

    // Retourne le numéro du rayon
    int getNoRayon();

};

#endif // RAYON_H
