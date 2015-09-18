/**
* @file generationpdf.cpp
* @brief Fichier de génération des Pdf
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 14:04:00
*/

#include "generationpdf.h"

//constructeur
GenerationPdf::GenerationPdf(QString n, QDate d)
{
    nom = n;
    dateGeneration = d;
}

GenerationPdf::GenerationPdf()
{
}

//ecrit le texte sur le pdf
void GenerationPdf::ecrireTexte(QString leTexte )
{

}

//ferme le document pdf
void GenerationPdf::fermer()
{

}
