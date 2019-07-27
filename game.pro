#-------------------------------------------------
#
# Project created by QtCreator 2017-07-03T10:25:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h

FORMS    += mainwindow.ui \
    game.ui

CONFIG += mobility
MOBILITY = 

