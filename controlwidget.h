#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

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
private:
    QPushButton pbClose;
    QPushButton pbMax;
    QPushButton pbMin;
    QPushButton pbTop;
    HoverButton pbShow;
    bool onTop;
    QTimer timer;
    bool hasCursor;

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:
    void requestClose();
    void requestMaximize();
    void requestMinimize();
    void requestTop();
    void sizeChange();

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
