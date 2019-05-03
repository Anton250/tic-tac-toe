#ifndef DEALINGWITHMAP_H
#define DEALINGWITHMAP_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QtDebug>
#include <QGraphicsRectItem>
#include <vector>

class dealingWithMap
{
public:
    dealingWithMap();
    void drawMap(QGraphicsRectItem * items[], QGraphicsScene & scene);
};

#endif // DEALINGWITHMAP_H
