#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QSplitter>
#include <QWebView>

#include "sc2tvstreamsprovider.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Sc2tvStreamsProvider sc2tvProvider;
    QQuickView qvStreamList;
    QSplitter *sSplitter;
    QWebView wvStreamView;
    QWidget *wStreamList;

private slots:
};

#endif // MAINWINDOW_H
