#include "webview.h"
#include <QDebug>
#include <QMouseEvent>

WebView::WebView(QWidget *parent) :
    QWebView(parent)
{
}

void WebView::mouseMoveEvent(QMouseEvent *event)
{
    if(event->pos().x()>this->width()-150 && event->pos().y()<40)
        emit showMenu();
}
