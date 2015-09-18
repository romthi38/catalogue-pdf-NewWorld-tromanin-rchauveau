#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T14:07:41
#
#-------------------------------------------------

QT       += core
QT       +=sql
QT       += printsupport
QT       +=gui

TARGET = Catalogue-New-World
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    generationpdf.cpp \
    rayon.cpp \
    typeproduit.cpp \
    produit.cpp

HEADERS += \
    generationpdf.h \
    rayon.h \
    typeproduit.h \
    produit.h
