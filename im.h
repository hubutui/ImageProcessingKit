#ifndef IM_H
#define IM_H

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QLabel>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

namespace Ui {
class im;
}

class im : public QMainWindow
{
    Q_OBJECT

public:
    explicit im(QWidget *parent = 0);
    ~im();

private slots:
    void on_action_Quit_triggered();

private:
    Ui::im *ui;
    QGraphicsScene *inScene, *outScene;
    QGraphicsPixmapItem *inPixmapItem, *outPixmapItem;
};

#endif // IM_H
