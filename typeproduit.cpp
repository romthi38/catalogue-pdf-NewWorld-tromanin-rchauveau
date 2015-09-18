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
    QSqlQuery requeteTP;
    requeteTP.exec("SELECT noTypeProduit, libelleTypeProduit FROM TYPEPRODUIT");
    while(requeteTP.next())
    {
        int noTypeProduit = requeteTP.value(0).toInt();
        QString libelleTypeProduit = requeteTP.value(1).toString();
    }
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
