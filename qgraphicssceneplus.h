#ifndef QGRAPHICSSCENEPLUS_H
#define QGRAPHICSSCENEPLUS_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class QGraphicsScenePlus : public QGraphicsScene
{
Q_OBJECT
public:
    QGraphicsScenePlus(QObject* parent = 0);

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);

signals:
    void sendCoord(QPointF);

public:
    QPointF point;
};

#endif // QGRAPHICSSCENEPLUS_H
