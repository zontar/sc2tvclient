#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

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

public slots:
    void setVisible(bool visible);

protected slots:
    void onPbClose();
    void onPbMax();
    void onPbMin();
    void onPbTop();
    void onTimer();

};

#endif // CONTROLWIDGET_H
