#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T12:26:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Viewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractstreamsprovider.cpp \
    abstractstreamitem.cpp \
    sc2tvstreamsprovider.cpp

HEADERS  += mainwindow.h \
    abstractstreamsprovider.h \
    abstractstreamitem.h \
    sc2tvstreamsprovider.h

FORMS    += mainwindow.ui

INCLUDEPATH +=  \
                ../Commons/SingleNetworkAccessManager \
                ../Commons/Downloader

Release:LIBS += -L../../libs/ -lSingleNetworkAccessManager -lDownloader
Debug:LIBS +=   -L../../libs/ -lSingleNetworkAccessManagerd -lDownloaderd


Debug:TARGET = $$join(TARGET,,,d)
DESTDIR = ../../bin
