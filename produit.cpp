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
    noProduit = n;
    libelleProduit = lib;
    prixUnitaireLot = pu;
    quantiteLot = qte;
    dateLimitConso = dlc;
    QSqlQuery requeteP;
    requeteP.exec("SELECT noProduit, libelleProduit, prixUnitaireLot, quantiteLot, dateLimitConso FROM PRODUIT");
    while(requeteP.next())
    {
        int noProduit = requeteP.value(0).toInt();
        QString libelleProduit = requeteP.value(1).toString();
        int prixUnitaireLot = requeteP.value(2).toInt();
        int quantiteLot = requeteP.value(3).toInt();
        QDate dateLimitConso = requeteP.value(4).toInt();
    }
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

