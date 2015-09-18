/**
* @file produit.cpp
* @brief Fichier des produits
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:00:00
*/

#include "produit.h"


//constructeur
Produit::Produit(int n, QString lib, int pu, int qte, QDate dlc)
{
    noProduit = no;
    libelleProduit = lib;
    prixUnitaireLot = pu;
    quantiteLot = qte;
    dateLimitConso = dlc;
}
Produit::Produit()
{
}


//retourne le libelle du produit
QString Produit::getLibelleProduit()
{
    return libelleProduit;
}

//retourne le prixUnitaire
int Produit::getPrixUnitaireLot()
{
    return prixUnitaireLot;
}


//retourne la quantite
int Produit::getQuantiteLot()
{
    return quantiteLot;
}


//retourne la dateLimiConso
QDate Produit::getDateLimiteConsomationLot()
{
    return dateLimitConso;
}

