/**
* @file rayon.cpp
* @brief Fichier des rayons
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:00:00
*/
#include "rayon.h"

//constructeur
Rayon::Rayon(int no, QString lib)
{
    noRayon=no;
    libelleRayon=lib;
}

Rayon::Rayon()
{
}


//retourne le libelle du rayon
Rayon::getLibelleRayon()
{
    return libelleRayon;
}

//retourne le numéro du rayon
Rayon::getNoRayon()
{
    return noRayon;
}
