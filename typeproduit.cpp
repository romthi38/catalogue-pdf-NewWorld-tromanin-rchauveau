/**
* @file typeproduit.cpp
* @brief Fichier des types de produits
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:00:00
*/

#include "typeproduit.h"

TypeProduit::TypeProduit(int n, QString l)
{
    noTypeProduit = n;
    libelleTypeProduit = l;
}

TypeProduit::TypeProduit()
{

}

QString TypeProduit::getLibelleTypeProduit()
{
    return libelleTypeProduit;
}

int TypeProduit::getNoTypeProduit()
{
    return noTypeProduit;
}
