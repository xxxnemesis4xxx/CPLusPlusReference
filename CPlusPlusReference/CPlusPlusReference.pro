#-------------------------------------------------
#
# Project created by QtCreator 2015-01-10T15:38:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPlusPlusReference
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    tuple.cpp \
    pair.cpp \
    iterator.cpp \
    funcobjandlambda.cpp

HEADERS  += dialog.h \
    categorie.h \
    tuple.h \
    pair.h \
    iterator.h \
    funcobjandlambda.h

FORMS    += dialog.ui
