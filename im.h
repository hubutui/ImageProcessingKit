#ifndef IM_H
#define IM_H

#include "qgraphicssceneplus.h"
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
#include <QPixmap>

// CImg 中用自己的函数来显示图像
// 但是 Qt 是跨平台，我们这里直接用 Qt 来做图像的显示
// 定义下面这个宏就可以不包含 CImg 用于显示图像的那部分
#define cimg_display 0
#include "CImg.h"

using namespace cimg_library;


namespace Ui {
class im;
}

class im : public QMainWindow
{
    Q_OBJECT

public:
    explicit im(QWidget *parent = 0);
    ~im();
    void cleanImage(void);

private slots:
    void on_action_Quit_triggered();

    void on_action_Open_triggered();

    void on_actionSave_as_triggered();

    void on_actionClose_triggered();

public slots:
    void showColorValue(const QPointF &position);

private:
    Ui::im *ui;
    QGraphicsScenePlus *inScene, *outScene;
    QPixmap inPixmap, outPixmap;
    QGraphicsPixmapItem *inPixmapItem, *outPixmapItem;

};

#endif // IM_H
