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
	abstractstreammodel.cpp \
    sc2tv/sc2tvstreamsprovider.cpp \
    sc2tv/sc2tvstreamitem.cpp \
    sc2tv/sc2tvstreammodel.cpp

HEADERS  += mainwindow.h \
    abstractstreamsprovider.h \
    abstractstreamitem.h \
	abstractstreammodel.h \
    sc2tv/sc2tvstreamsprovider.h \
    sc2tv/sc2tvstreamitem.h \
    sc2tv/sc2tvstreammodel.h

FORMS    +=

INCLUDEPATH +=  .\
				sc2tv \
                ../Commons/SingleNetworkAccessManager \
                ../Commons/Downloader

Release:LIBS += -L../../libs/ -lDownloader -lSingleNetworkAccessManager
Debug:LIBS +=   -L../../libs/ -lDownloaderd -lSingleNetworkAccessManagerd


Debug:TARGET = $$join(TARGET,,,d)
DESTDIR = ../../bin

OTHER_FILES += \
    ui/StreamList.qml \
    sc2tv/Sc2tvDelegate.qml

RESOURCES += rc.qrc

RC_FILE = viewer.rc
