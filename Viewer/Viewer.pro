#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T12:26:42
#
#-------------------------------------------------

QT       += core gui quick network widgets webkitwidgets
CONFIG += c++11

TARGET = Viewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractstreamsprovider.cpp \
    abstractstreamitem.cpp \
    sc2tvstreamsprovider.cpp \
    sc2tvstreamitem.cpp

HEADERS  += mainwindow.h \
    abstractstreamsprovider.h \
    abstractstreamitem.h \
    sc2tvstreamsprovider.h \
    sc2tvstreamitem.h

FORMS    +=

INCLUDEPATH +=  \
                ../Commons/SingleNetworkAccessManager \
                ../Commons/Downloader

Release:LIBS += -L../../libs/ -lDownloader -lSingleNetworkAccessManager
Debug:LIBS +=   -L../../libs/ -lDownloaderd -lSingleNetworkAccessManagerd


Debug:TARGET = $$join(TARGET,,,d)
DESTDIR = ../../bin

OTHER_FILES += \
    ui/StreamList.qml

RESOURCES += rc.qrc

RC_FILE = viewer.rc
