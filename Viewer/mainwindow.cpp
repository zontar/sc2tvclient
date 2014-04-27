#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQmlContext>
#include "sc2tvstreammodel.h"
#include "sc2tvstreamsprovider.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    wvStreamView.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    wvStreamView.page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    m_provider = new Sc2tvStreamsProvider();
    m_model = new Sc2tvStreamModel();

    qvStreamList.setResizeMode(QQuickView::SizeRootObjectToView);
    qvStreamList.rootContext()->setContextProperty("StreamModel", m_model);
    qvStreamList.setSource(QUrl("qrc:///ui/StreamList.qml"));
    wStreamList = QWidget::createWindowContainer(&qvStreamList);

    sSplitter = new QSplitter(Qt::Vertical, this);
    sSplitter->setStyleSheet("QSplitter{\nborder-image: url(:/images/background.jpg);\n}\n\n \
                           QSplitterHandle{\nbackground-color: #82817e;\nwidth: 5px;\nheight: 5px;\n}\n\n \
                           QWebView{\nbackground-color: rgba(0, 0, 0,0);\n}\n");
    sSplitter->addWidget(&wvStreamView);
    //ToDo: Неведомая херня в сочетании сплиттера и квиквью. Pure virtual call при удалении спилиттера. Пока решена неудалением сплиттера, проверить баг в 5.3
    sSplitter->addWidget(wStreamList);


    setCentralWidget(sSplitter);

    connect(m_provider, SIGNAL(found(AbstractStreamItem)), m_model, SLOT(addItem(AbstractStreamItem)));
    connect(m_provider, SIGNAL(error(QString)), this, SLOT(providerError(QString)));
    connect(m_model, SIGNAL(foundUrls(QStringList)), this, SLOT(foundUrls(QStringList)));
    connect(m_model, SIGNAL(error(QString)), this, SLOT(modelError(QString)));
    m_provider->get();

}

MainWindow::~MainWindow()
{
//    sSplitter->deleteLater();
    //    wStreamList->deleteLater();
}

void MainWindow::foundUrls(const QStringList &urls)
{
    qDebug() << urls;
/*
    QFile f("://ui/page.html");
    f.open(QIODevice::ReadOnly);
    QString page = f.readAll();
    f.close();*/
    wvStreamView.stop();
    //wvStreamView.setHtml(page.arg(urls[0]));
    wvStreamView.load(QUrl(urls[0]));
}

void MainWindow::modelError(const QString &description)
{
    qDebug() << "[Model error] " << description;
}

void MainWindow::providerError(const QString &description)
{
    qDebug() << "[Provider error] " << description;
}
