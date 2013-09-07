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

    pbTop.setGeometry(7,4,32,32);
    pbMin.setGeometry(43,4,32,32);
    pbMax.setGeometry(77,4,32,32);
    pbClose.setGeometry(111,4,32,32);
    this->setFixedSize(150,40);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,46,118,204));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    pbClose.setStyleSheet("border-image: url(:/image/wclose.png)");
    pbMax.setStyleSheet("border-image: url(:/image/wmax.png)");
    pbMin.setStyleSheet("border-image: url(:/image/wmin.png)");
    pbTop.setStyleSheet("border-image: url(:/image/wtop.png)");
    connect(&pbClose,SIGNAL(clicked()),this,SLOT(onPbClose()));
    connect(&pbMax,SIGNAL(clicked()),this,SLOT(onPbMax()));
    connect(&pbMin,SIGNAL(clicked()),this,SLOT(onPbMin()));
    connect(&pbTop,SIGNAL(clicked()),this,SLOT(onPbTop()));
    this->setWindowOpacity(0.8);

}

void ControlWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    timer.singleShot(2000,this,SLOT(onTimer()));
}

void ControlWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    timer.stop();
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
    setVisible(false);
}
