#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QSplitter>
#include <QWebView>

#include "abstractstreamsprovider.h"
#include "abstractstreammodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QQuickView qvStreamList;
    QSplitter *sSplitter;
    QWebView wvStreamView;
    QWidget *wStreamList;
    AbstractStreamModel *m_model;
    AbstractStreamsProvider *m_provider;

private slots:
};

#endif // MAINWINDOW_H
