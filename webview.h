#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebView>

class WebView : public QWebView
{
    Q_OBJECT
public:
    explicit WebView(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *);

signals:
    void showMenu();

public slots:

};

#endif // WEBVIEW_H
