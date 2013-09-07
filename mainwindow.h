#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QSplitter>
#include <QTimer>
#include "webview.h"
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
    WebView view;
    QWidget *qmlWidget;
    ControlWidget *controls;
    StreamRipper ripper;
    StreamPreviewModel streamModel;
    QTimer timer;

protected slots:
    void loadStream(const QString &link);
    void onShowMenu();
    void onTop();
    void onTimer();
};

#endif // MAINWINDOW_H
