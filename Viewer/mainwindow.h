#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sc2tvstreamsprovider.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Sc2tvStreamsProvider sc2tvProvider;

private slots:
};

#endif // MAINWINDOW_H
