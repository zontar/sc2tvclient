#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QSplitter>
#include <QTimer>
#include <QWebView>
#include "controlwidget.h"
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

protected:
    void resizeEvent(QResizeEvent * event);

private:
    QSplitter splitter;
    QQuickView qml;
    QWebView view;
    QWidget *qmlWidget;
    ControlWidget *controls;
    StreamRipper ripper;
    StreamPreviewModel streamModel;
    QTimer timer;

protected slots:
    void loadStream(const QString &link);
    void onTop();
    void onMaximixe();
    void controlsChanged();
};

#endif // MAINWINDOW_H
