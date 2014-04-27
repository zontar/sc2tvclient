#-------------------------------------------------
#
# Project created by QtCreator 2014-02-11T00:25:42
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = SingleNetworkAccessManager
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += singlenetworkaccessmanager.cpp

HEADERS += singlenetworkaccessmanager.h

Debug:TARGET = $$join(TARGET,,,d)

DESTDIR = ../../../libs
