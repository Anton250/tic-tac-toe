#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QtDebug>
#include <QPainterPath>
#include <QRectF>
#include <vector>
#include <ctime>
#include <random>
#include <dealingwithmap.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QGraphicsView, dealingWithMap
{
    Q_OBJECT
private slots:
    void keyPressEvent(QKeyEvent *key);
    void drawNumNum();
signals:
    void addNumNum();

public:
    explicit MainWindow(int h, int w,QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsTextItem score;
    QGraphicsEllipseItem ellipse, numNum;
    QRandomGenerator rand;
    QGraphicsRectItem * rects[34];
    QPainterPath setPath(QGraphicsRectItem * rect);
    bool checkRect(qreal x, qreal y);
    bool checkValidNumNum(qreal x, qreal y);
    void checkNumNum(qreal x, qreal y);
    int userScore = 0;

};

#endif // MAINWINDOW_H
