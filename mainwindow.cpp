#include "mainwindow.h"
#include <QVBoxLayout>
#include <QQmlContext>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QVBoxLayout *layout = new QVBoxLayout();
    view.settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    QObject::connect(&ripper,SIGNAL(funStreamFound(StreamPreviewItem)),&streamModel,SLOT(addItem(StreamPreviewItem)));
    QObject::connect(&streamModel,SIGNAL(showStream(QString)),this,SLOT(loadStream(QString)));
    qml.setSource(QUrl("qrc:///ui/streamlist.qml"));
    qml.rootContext()->setContextProperty("streammodel", &streamModel);
    qml.setResizeMode(QQuickView::SizeRootObjectToView);
    qmlWidget = QWidget::createWindowContainer(&qml);
    qmlWidget->setFixedHeight(250);

    layout->addWidget(&view);
    layout->addWidget(qmlWidget);
    mainWidget.setLayout(layout);
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::black);
    mainWidget.setAutoFillBackground(true);
    mainWidget.setPalette(p);
    setCentralWidget(&mainWidget);
    ripper.load();
}

MainWindow::~MainWindow()
{
    //qmlWidget->deleteLater();
}

void MainWindow::loadStream(const QString &link)
{
    view.stop();
    view.setUrl(link);
}
