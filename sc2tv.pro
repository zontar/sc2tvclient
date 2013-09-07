#-------------------------------------------------
#
# Project created by QtCreator 2013-09-06T14:00:04
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sc2tv
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    streamripper.cpp \
    streampreviewmodel.cpp \
    streampreviewitem.cpp \
    stream.cpp \
    imagestore.cpp \
    controlwidget.cpp \
    webview.cpp

HEADERS  += mainwindow.h \
    streamripper.h \
    streampreviewmodel.h \
    streampreviewitem.h \
    stream.h \
    imagestore.h \
    controlwidget.h \
    webview.h

FORMS    +=

OTHER_FILES += \
    streamlist.qml

RESOURCES += \
    res.qrc
