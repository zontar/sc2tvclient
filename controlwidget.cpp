#include "controlwidget.h"
#include <QPalette>
#include <QMouseEvent>
#include <QDebug>

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent), onTop(false), hasMousePress(false), controlsVisible(true)
{
    pbTop.setFixedSize(32,32);
    pbMin.setFixedSize(32,32);
    pbMax.setFixedSize(32,32);
    pbClose.setFixedSize(32,32);
    pbShow.setFixedSize(32,32);
    hbLayout.setMargin(0);
    hbLayout.addStretch();
    hbLayout.addWidget(&pbTop);
    hbLayout.addWidget(&pbMin);
    hbLayout.addWidget(&pbMax);
    hbLayout.addWidget(&pbClose);
    hbLayout.addWidget(&pbShow);
    setFixedHeight(40);
    setLayout(&hbLayout);
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
    hideControls();
}

bool ControlWidget::isConrolsVisible()
{
    return controlsVisible;
}

void ControlWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    hasCursor = true;
    timer.stop();
}

void ControlWidget::leaveEvent(QEvent *)
{
    hasCursor = false;
    timer.singleShot(2000,this,SLOT(onTimer()));
}

void ControlWidget::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && hasMousePress)
    {
     //   moveRequest(event->globalX()-oldPos.x(), event->globalY()-oldPos.y());
        qDebug() << "move on " << event->globalPos() << "; delta:" <<event->globalPos()-oldPos;
        moveRequest(event->globalPos()-oldPos);
    }

}

void ControlWidget::mousePressEvent(QMouseEvent *event)
{
    hasMousePress = true;
    qDebug() << "mouse press on " << event->globalPos();
    oldPos = event->globalPos();
}

void ControlWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    hasMousePress = false;
}

void ControlWidget::showControls()
{
    setFixedHeight(40);
    setGeometry(0,0,parentWidget()->width(),40);
    pbClose.show();
    pbMax.show();
    pbMin.show();
    pbTop.show();
    pbShow.hide();
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,46,118,204));
    setPalette(p);
    controlsVisible = true;
    emit sizeChange();
}

void ControlWidget::hideControls()
{
    pbClose.hide();
    pbMax.hide();
    pbMin.hide();
    pbTop.hide();
    pbShow.show();
    setFixedHeight(32);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(00,00,00,00));
    setPalette(p);
    controlsVisible = false;
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
    if(!hasCursor)hideControls();
}


void HoverButton::enterEvent(QEvent *)
{
    emit hover();
}
