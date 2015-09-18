/**
* @file produit.h
* @brief Classe de Produit
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:04:00
* @class Produit
*/
#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <iostream>
#include <QDate>
#include "typeproduit.h"

using namespace std;

/**
 * @class Classe Produit
 * @brief Classe représentant le produit
 * Private :
 * nom du produit
 * libelle du produit
 * Public :
 * Constructeur Produit
 * @fn getLibelleProduit
 * @brief retourne le libelle du produit
 * @fn getPrixUnitaireLot
 * @brief retourne la prix unitaire du produit
 * @fn getQuantiteLot
 * @brief retourne la quantite du lot
 * @fn getDateLimiteConsomationLot
 * @brief retourne la date limite de consomation
 */
class Produit
{
private:
    int noProduit; //numéro du produit
    QString libelleProduit; //libelle du produit
    int prixUnitaireLot; //prix unitaire du lot de produit
    int quantiteLot; //quantite de produit dans le lot
    QDate dateLimitConso; //date limitConso des produits

public:
    //constructeur
    Produit(int n, QString lib, int pu, int qte, QDate dlc);
    Produit();

    //retourne le libelle du produit
    QString getLibelleProduit();
    //retourne le pix unitaire du produit
    int getPrixUnitaireLot();
    //retourne la quantite du lot
    int getQuantiteLot();
    //retourne la date limite de consomation
    QDate getDateLimiteConsomationLot();

};

#endif // PRODUIT_H
