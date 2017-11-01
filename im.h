#ifndef IM_H
#define IM_H

#include "qgraphicssceneplus.h"
#include "dialogadjusthsv.h"
#include "ui_dialogadjusthsv.h"
#include "dialoglineartransform.h"
#include "ui_dialoglineartransform.h"
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

// here we use Qt for GUI
// disable CImg's display function by define this macro
#define cimg_display 0
#include <CImg.h>

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

    void on_actionAdjust_HSV_triggered();

    void on_action_Grayscale_triggered();

    void on_action_Linear_transformation_triggered();

public slots:
    void showColorValue(const QPointF &position);
    void adjustHsv(const int &h, const float &s, const float &v);
    void linearTransformation(const double &k, const double &b);

private:
    Ui::im *ui;
    QGraphicsScenePlus *inScene, *outScene;
    QPixmap *inPixmap, *outPixmap;
    QGraphicsPixmapItem *inPixmapItem, *outPixmapItem;
    DialogAdjustHsv *dialogAdjustHsv;
    DialogLinearTransform *dialogLinearTransform;
    QString fileName;
    void setFileName(const QString &fileName);
    void updateOutScene(const QString &fileName);
    inline int rgbToGray(const int &r, const int &g, const int &b);
};

#endif // IM_H
