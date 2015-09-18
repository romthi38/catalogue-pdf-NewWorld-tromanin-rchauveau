/**
* @file typeproduit.h
* @brief Classe de TypeProduit
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 15:04:00
* @class TypeProduit
*/

#ifndef TYPEPRODUIT_H
#define TYPEPRODUIT_H

#include "rayon.h"
class TypeProduit
{
private:
    int noTypeProduit;
    QString libelleTypeProduit;
public:
    TypeProduit(int n, QString l);
    TypeProduit();
    QString getLibelleTypeProduit();
    int getNoTypeProduit();
};

#endif // TYPEPRODUIT_H
