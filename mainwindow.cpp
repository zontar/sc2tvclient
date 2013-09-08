#include "mainwindow.h"
#include <QVBoxLayout>
#include <QQmlContext>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    view.settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    QObject::connect(&ripper,SIGNAL(funStreamFound(StreamPreviewItem)),&streamModel,SLOT(addItem(StreamPreviewItem)));
    QObject::connect(&stream,SIGNAL(streamReady(QString)),this,SLOT(loadStream(QString)));
    proxyModel.setSourceModel(&streamModel);
    proxyModel.setSortRole(StreamPreviewModel::RatingRole);
    proxyModel.sort(0,Qt::DescendingOrder);
    qml.setSource(QUrl("qrc:///ui/streamlist.qml"));
    qml.rootContext()->setContextProperty("streammodel", &proxyModel);
    qml.rootContext()->setContextProperty("stream", &stream);
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
    controls = new ControlWidget(this);
    QObject::connect(controls,SIGNAL(requestClose()),this,SLOT(close()));
    QObject::connect(controls,SIGNAL(requestMaximize()),this,SLOT(onMaximixe()));
    QObject::connect(controls,SIGNAL(requestMinimize()),this,SLOT(showMinimized()));
    QObject::connect(controls,SIGNAL(requestTop()),this,SLOT(onTop()));
    QObject::connect(controls,SIGNAL(sizeChange()),this,SLOT(controlsChanged()));
    QObject::connect(controls,SIGNAL(moveRequest(QPoint)),this,SLOT(moveWindow(QPoint)));
    ripper.load();
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
    this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
}

MainWindow::~MainWindow()
{
    //qmlWidget->deleteLater();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
   Q_UNUSED(event)
   controlsChanged();
}

void MainWindow::loadStream(const QString &link)
{
    qDebug() << "start load stream: " << link;
    view.stop();
    view.load(QUrl(link));
}

void MainWindow::onTop()
{
    if(windowFlags()&Qt::WindowStaysOnTopHint)
    {
        setWindowFlags( windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
    else
    {
        setWindowFlags(Qt::WindowStaysOnTopHint);
        this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
        this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
    }
    show();
}

void MainWindow::onMaximixe()
{
    if(this->isMaximized()) showNormal();
    else showMaximized();
}

void MainWindow::controlsChanged()
{
    if(controls->isConrolsVisible())
    {
        controls->setGeometry(0,0,this->width(),32);
    }
    else
    {
        controls->setGeometry(this->width()-32,0,32,32);
    }
}

void MainWindow::moveWindow(QPoint delta)
{
    move(this->pos()+delta);
}
