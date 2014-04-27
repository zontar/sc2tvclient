#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    wvStreamView.settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    wvStreamView.page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    qvStreamList.setSource(QUrl("qrc:///ui/StreamList.qml"));
    qvStreamList.setResizeMode(QQuickView::SizeRootObjectToView);
    wStreamList = QWidget::createWindowContainer(&qvStreamList);

    sSplitter = new QSplitter(Qt::Vertical, this);
    sSplitter->setStyleSheet("QSplitter{\nborder-image: url(:/images/background.jpg);\n}\n\n \
                           QSplitterHandle{\nbackground-color: #82817e;\nwidth: 5px;\nheight: 5px;\n}\n\n \
                           QWebView{\nbackground-color: rgba(0, 0, 0,0);\n}\n");
    sSplitter->addWidget(&wvStreamView);
    //ToDo: Неведомая херня в сочетании сплиттера и квиквью. Pure virtual call при удалении спилиттера. Пока решена неудалением сплиттера, проверить баг в 5.3
    sSplitter->addWidget(wStreamList);


    setCentralWidget(sSplitter);

 //   sc2tvProvider.get();
}

MainWindow::~MainWindow()
{
//    sSplitter->deleteLater();
//    wStreamList->deleteLater();
}
