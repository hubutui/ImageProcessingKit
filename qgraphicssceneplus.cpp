#include "qgraphicssceneplus.h"
#include "QDebug"

QGraphicsScenePlus::QGraphicsScenePlus(QObject *parent) : QGraphicsScene(parent)
{
    //point.setX(0);
    //point.setY(0);

    update();
}

void QGraphicsScenePlus::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    point.setX(mouseEvent->pos().x());
    point.setY(mouseEvent->pos().y());

    //emit sendCoord(point);

    update();
}

void QGraphicsScenePlus::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    point.setX(mouseEvent->scenePos().x());
    point.setY(mouseEvent->scenePos().y());

    //qDebug() << point.x() << ", " << point.y() << endl;

    emit sendCoord(point);
}

