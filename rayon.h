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

class Rayon
{
private:
    int noRayon; // numéro du rayon
    QString libelleRayon; //libelle du rayon

public:
    //constructeur
    Rayon(int no, QString lib);
    Rayon();

    //retourne le libelle du rayon
    QString getLibelleRayon();

    //retourne le numéro du rayon
    int getNoRayon();

};

#endif // RAYON_H
