#include "mainwindow.h"
#include <QVBoxLayout>
#include <QQmlContext>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    view.settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    QObject::connect(&ripper,SIGNAL(funStreamFound(StreamPreviewItem)),&streamModel,SLOT(addItem(StreamPreviewItem)));
    QObject::connect(&streamModel,SIGNAL(showStream(QString)),this,SLOT(loadStream(QString)));
    qml.setSource(QUrl("qrc:///ui/streamlist.qml"));
    qml.rootContext()->setContextProperty("streammodel", &streamModel);
    qml.setResizeMode(QQuickView::SizeRootObjectToView);
    qmlWidget = QWidget::createWindowContainer(&qml);
    qmlWidget->setFixedHeight(240);
    splitter.addWidget(&view);
    splitter.addWidget(qmlWidget);
    splitter.setStyleSheet("QSplitter{\nborder-image: url(:/image/background.jpg);\n}\n\n \
                           QSplitterHandle{\nbackground-color: #82817e;\nwidth: 5px;\nheight: 5px;\n}\n\n \
                           QWebView{\nbackground-color: rgba(0, 0, 0,0);\n}\n");
    splitter.setOrientation(Qt::Vertical);

    setCentralWidget(&splitter);
 //   setWindowOpacity(0.5);
    ripper.load();
}

MainWindow::~MainWindow()
{
    //qmlWidget->deleteLater();
}

void MainWindow::loadStream(const QString &link)
{
    qDebug() << "start load stream: " << link;
    view.stop();
    view.load(QUrl(link));
}
