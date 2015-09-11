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
    int noProduit;
    QString libelleProduit;

public:
    //constructeur
    Produit(int n, QString lib);
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
