#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QHBoxLayout>

class HoverButton: public QPushButton
{
    Q_OBJECT
protected:
    void enterEvent(QEvent *);
signals:
    void hover();
};

class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlWidget(QWidget *parent = 0);
    bool isConrolsVisible();
private:
    QPushButton pbClose;
    QPushButton pbMax;
    QPushButton pbMin;
    QPushButton pbTop;
    HoverButton pbShow;
    bool onTop;
    QTimer timer;
    bool hasCursor;
    bool hasMousePress;
    QPoint oldPos;
    bool controlsVisible;
    QHBoxLayout hbLayout;

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

signals:
    void requestClose();
    void requestMaximize();
    void requestMinimize();
    void requestTop();
    void sizeChange();
    void moveRequest(QPoint delta);

protected slots:
    void onPbClose();
    void onPbMax();
    void onPbMin();
    void onPbTop();
    void onTimer();
    void showControls();
    void hideControls();

};

#endif // CONTROLWIDGET_H
