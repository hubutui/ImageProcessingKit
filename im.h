#ifndef IM_H
#define IM_H

#include "dialogcustomfilter.h"
#include "ui_dialogcustomfilter.h"
#include "dialogminimumfilter.h"
#include "ui_dialogminimumfilter.h"
#include "dialogmaximumfilter.h"
#include "ui_dialogmaximumfilter.h"
#include "dialogmedianfilter.h"
#include "ui_dialogmedianfilter.h"
#include "dialogavaragefilter.h"
#include "ui_dialogavaragefilter.h"
#include "dialogpiecewiselineartransformation.h"
#include "ui_dialogpiecewiselineartransformation.h"
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
#include <QMap>

// here we use Qt for GUI
// disable CImg's display function by define this macro
//#define cimg_display 0
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

    void on_action_Histogram_triggered();

    void on_actionHistogram_equalization_triggered();

    void on_actionHistogram_specication_triggered();

    void on_actionPiecewise_linear_transformation_triggered();

    void on_actionAverage_filter_triggered();

    void on_actionLaplacian_filter_triggered();

    void on_actionMedian_filter_triggered();

    void on_actionMaximum_filter_triggered();

    void on_actionMinimum_filter_triggered();

    void on_actionCustomFilter_triggered();

    void on_actionPseudocolor_triggered();

    void on_action_Save_triggered();

public slots:
    void showColorValue(const QPointF &position);
    void adjustHsv(const int &h, const float &s, const float &v);
    void linearTransformation(const double &k, const double &b);
    void piecewiseLinearTransformation(const double &r1, const double &s1, const double &r2, const double &s2);
    void averageFilter(const int &size);
    void medianFilter(const int &size);
    void maximumFilter(const int &size);
    void minimumFilter(const int &size);
    void customFilter(const int &w00, const int &w01, const int &w02,
                      const int &w10, const int &w11, const int &w12,
                      const int &w20, const int &w21, const int &w22);

private:
    Ui::im *ui;
    QGraphicsScenePlus *inScene, *outScene;
    QPixmap *inPixmap, *outPixmap;
    QGraphicsPixmapItem *inPixmapItem, *outPixmapItem;
    DialogAdjustHsv *dialogAdjustHsv;
    DialogLinearTransform *dialogLinearTransform;
    QString fileName;
    QString saveFileName;
    void setFileName(const QString &fileName);
    void setSaveFileName(const QString &saveFileName);
    void updateOutScene(const QString &fileName);
    inline int rgbToGray(const int &r, const int &g, const int &b);
    // QMap<int, int> getHistogramEqualizationMap(const CImg<int> img, const int nLevel);
    template<typename T>
    QMap<T, T> getHistogramEqualizationMap(const CImg<T> &img, const int &nLevel = 256);
    template<typename T>
    QMap<T, T> getHistogramSpecificationMap(const CImg<T> &src, const CImg<T> &ref, const int &nLevel = 256);
    // get position of pixel with minimum value of image img
    // where img is nLevel * 1 size
    // nLevel is the gray value range
    template<typename T>
    int getMinimumPos(const CImg<T> &img);

    DialogPiecewiseLinearTransformation *dlgPiecewiseLinearTranformation;
    DialogAvarageFilter *dlgAverageFilter;
    DialogMedianFilter *dlgMedianFilter;
    DialogMaximumFilter *dlgMaximumFilter;
    DialogMinimumFilter *dlgMinimumFilter;
    DialogCustomFilter *dlgCustomFilter;

    template <typename T>
    bool isGrayscale(const CImg<T> &img);
    template <typename T>
    bool isRGB(const CImg<T> &img);
};

#endif // IM_H
