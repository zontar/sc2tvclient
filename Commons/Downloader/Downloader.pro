#-------------------------------------------------
#
# Project created by QtCreator 2014-02-11T00:24:16
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = Downloader
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += downloader.cpp

HEADERS += downloader.h

INCLUDEPATH +=  ../../Commons/SingleNetworkAccessManager

Debug:TARGET = $$join(TARGET,,,d)

Release:LIBS += ../../libs/libSingleNetworkAccessManager.a
Debug:LIBS +=   ../../libs/libSingleNetworkAccessManagerd.a

DESTDIR = ../../../libs
