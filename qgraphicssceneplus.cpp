#include "qgraphicssceneplus.h"
#include "QDebug"

QGraphicsScenePlus::QGraphicsScenePlus(QObject *parent) : QGraphicsScene(parent)
{
    position.setX(0);
    position.setY(0);
}

void QGraphicsScenePlus::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    position.setX(mouseEvent->scenePos().x());
    position.setY(mouseEvent->scenePos().y());

    emit coordChanged(position);
}

void QGraphicsScenePlus::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    position.setX(mouseEvent->scenePos().x());
    position.setY(mouseEvent->scenePos().y());

    emit coordChanged(position);
}


