/**
* @file rayon.cpp
* @brief Fichier des rayons
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:00:00
*/
#include "rayon.h"

// Constructeur du rayon
Rayon::Rayon(int no, QString lib)
{
    noRayon=no;
    libelleRayon=lib;

    // On récupère les champs dans la BDD
    QSqlQuery requeteR;
    requeteR.exec("SELECT noRayon, libelleRayon FROM RAYON");
    while(requeteR.next())
    {
        int noRayon = requeteR.value(0).toInt();
        QString libelleRayon = requeteR.value(1).toString();
    }
}

// Constructeur vide
Rayon::Rayon()
{
}


// Retourne le libelle du rayon
QString Rayon::getLibelleRayon()
{
    return libelleRayon;
}

// Retourne le numéro du rayon
int Rayon::getNoRayon()
{
    return noRayon;
}
