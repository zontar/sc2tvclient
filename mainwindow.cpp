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
                           QWebView{\nbackground-color: rgba(0, 0, 0,255);\n}\n");
    splitter.setOrientation(Qt::Vertical);
    setCentralWidget(&splitter);
    controls = new ControlWidget(this);
    QObject::connect(controls,SIGNAL(requestClose()),this,SLOT(close()));
    QObject::connect(controls,SIGNAL(requestMaximize()),this,SLOT(showMaximized()));
    QObject::connect(controls,SIGNAL(requestMinimize()),this,SLOT(showMinimized()));
    QObject::connect(controls,SIGNAL(requestTop()),this,SLOT(onTop()));
    QObject::connect(&view,SIGNAL(showMenu()),this,SLOT(onShowMenu()));
    ripper.load();
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
    this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
    this->setWindowFlags(Qt::FramelessWindowHint); //Set a frameless window
}

MainWindow::~MainWindow()
{
    //qmlWidget->deleteLater();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
   Q_UNUSED(event)
   controls->setGeometry(this->width()-150,0,150,40);
}

void MainWindow::loadStream(const QString &link)
{
    qDebug() << "start load stream: " << link;
    view.stop();
    view.load(QUrl(link));
}

void MainWindow::onShowMenu()
{
    qDebug() << "show";
    controls->setVisible(true);
}

void MainWindow::onTop()
{
    if(windowFlags()&Qt::WindowStaysOnTopHint)
    {
        qDebug() << "1";
        setWindowFlags( windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
    else
    {
        qDebug() << "2";
        setWindowFlags(Qt::WindowStaysOnTopHint);
    }
    show();
    timer.singleShot(5000,this,SLOT(onTimer()));
}

void MainWindow::onTimer()
{
    controls->setVisible(false);
}
