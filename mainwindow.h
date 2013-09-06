#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QWebView>
#include "streampreviewmodel.h"
#include "streamripper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    QWidget mainWidget;
    QQuickView qml;
    QWebView view;
    QWidget *qmlWidget;
    StreamRipper ripper;
    StreamPreviewModel streamModel;
protected slots:
    void loadStream(const QString &link);
};

#endif // MAINWINDOW_H
