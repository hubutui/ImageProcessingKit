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
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* mouseEvent) override;

signals:
    void coordChanged(const QPointF&);
    void seedSetted(const QPoint&);

private:
    // we save position of the mouse cursor in QPoint position
    QPointF position;
    QPoint seedPosition;
};

#endif // QGRAPHICSSCENEPLUS_H
