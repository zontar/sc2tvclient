#include "controlwidget.h"
#include <QPalette>
#include <QDebug>

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent), onTop(false)
{
    pbClose.setParent(this);
    pbMax.setParent(this);
    pbMin.setParent(this);
    pbTop.setParent(this);
    pbShow.setParent(this);

    pbTop.setGeometry(7,4,32,32);
    pbMin.setGeometry(43,4,32,32);
    pbMax.setGeometry(77,4,32,32);
    pbClose.setGeometry(111,4,32,32);
    pbShow.setGeometry(0,0,32,32);
    this->setFixedSize(150,40);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,46,118,204));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    pbClose.setStyleSheet("border-image: url(:/image/wclose.png)");
    pbMax.setStyleSheet("border-image: url(:/image/wmax.png)");
    pbMin.setStyleSheet("border-image: url(:/image/wmin.png)");
    pbTop.setStyleSheet("border-image: url(:/image/wtop.png)");
    pbShow.setStyleSheet("border-image: url(:/image/triangle.png)");
    connect(&pbClose,SIGNAL(clicked()),this,SLOT(onPbClose()));
    connect(&pbMax,SIGNAL(clicked()),this,SLOT(onPbMax()));
    connect(&pbMin,SIGNAL(clicked()),this,SLOT(onPbMin()));
    connect(&pbTop,SIGNAL(clicked()),this,SLOT(onPbTop()));
    connect(&pbShow,SIGNAL(hover()),this,SLOT(showControls()));
    this->setWindowOpacity(0.8);
//    timer.singleShot(2000,this,SLOT(onTimer()));
    hideControls();
}

void ControlWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    timer.stop();
}

void ControlWidget::leaveEvent(QEvent *)
{
    timer.singleShot(2000,this,SLOT(onTimer()));
}

void ControlWidget::showControls()
{
    setFixedSize(150,40);
    pbClose.show();
    pbMax.show();
    pbMin.show();
    pbTop.show();
    pbShow.hide();
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,46,118,204));
    setPalette(p);
    emit sizeChange();
}

void ControlWidget::hideControls()
{
    pbClose.hide();
    pbMax.hide();
    pbMin.hide();
    pbTop.hide();
    pbShow.show();
    setFixedSize(32,32);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,00,00,00));
    setPalette(p);
    emit sizeChange();
}

void ControlWidget::onPbClose()
{
    emit requestClose();
}

void ControlWidget::onPbMax()
{
    emit requestMaximize();
}

void ControlWidget::onPbMin()
{
    emit requestMinimize();
}

void ControlWidget::onPbTop()
{
    if(onTop)pbTop.setStyleSheet("border-image: url(:/image/wtop.png)");
    else pbTop.setStyleSheet("border-image: url(:/image/btop.png)");
    onTop = !onTop;
    emit requestTop();
}

void ControlWidget::onTimer()
{
    hideControls();
}


void HoverButton::enterEvent(QEvent *)
{
    emit hover();
}
