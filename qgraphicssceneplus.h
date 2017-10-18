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
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;

signals:
    void coordChanged(const QPointF&);

private:
    // we save position of the mouse cursor in QPoint position
    QPointF position;
};

#endif // QGRAPHICSSCENEPLUS_H
