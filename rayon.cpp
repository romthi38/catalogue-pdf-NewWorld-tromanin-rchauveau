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
