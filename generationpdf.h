/**
* @file generationpdf.h
* @brief Classe de GenerationPdf
* @author tromanin
* @author rchauveau
* @date vendredi 11 septembre 2015, 14:04:00
* @class GenerationPdf
*/

#ifndef GENERATIONPDF_H
#define GENERATIONPDF_H

#include <QString>
#include <iostream>
#include <QDate>

class GenerationPdf
{
public:
    QString nom;
    QDate dateGeneration;

    GenerationPdf(QString n, QDate d);
    GenerationPdf();

    //ecrit le texte sur le pdf
    void ecrireTexte(QString leTexte );
    //ferme le document pdf
    void fermer();
};

#endif // GENERATIONPDF_H
