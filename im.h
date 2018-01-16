#ifndef IM_H
#define IM_H

#include "dialogifft.h"
#include "dialogwienerfilter.h"
#include "dialogatmosphericcirculation.h"
#include "dialoggaussiannoise.h"
#include "dialoginversefilter.h"
#include "dialogmotionblur.h"
#include "dialoghomomorphicfilter.h"
#include "dialogbutterworthhighpassfilter.h"
#include "dialogbutterworthlowpassfilter.h"
#include "dialogideallowpassfilter.h"
#include "dialogidealhighpassfilter.h"
#include "ui_dialogidealhighpassfilter.h"
#include "dialogclosing.h"
#include "ui_dialogclosing.h"
#include "dialogopening.h"
#include "ui_dialogopening.h"
#include "dialogdilate.h"
#include "ui_dialogdilate.h"
#include "dialogregiongrowth.h"
#include "ui_dialogregiongrowth.h"
#include "dialogerode.h"
#include "ui_dialogerode.h"
#include "dialogmanualthreshold.h"
#include "ui_dialogmanualthreshold.h"
#include "dialogresize.h"
#include "ui_dialogresize.h"
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
// include qt_windows.h for Windows target only.
#include <QtGlobal>
#ifdef Q_OS_WIN
#include <qt_windows.h>
#endif
#include <complex>

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

    void on_action_Save_As_triggered();

    void on_action_Close_triggered();

    void on_action_Adjust_HSV_triggered();

    void on_action_Grayscale_triggered();

    void on_action_Linear_Transformation_triggered();

    void on_action_Histogram_triggered();

    void on_action_Histogram_Equalization_triggered();

    void on_action_Histogram_Specification_triggered();

    void on_action_Piecewise_Linear_Transformation_triggered();

    void on_action_Average_Filter_triggered();

    void on_action_Laplacian_Filter_triggered();

    void on_action_Median_Filter_triggered();

    void on_action_Maximum_Filter_triggered();

    void on_action_Minimum_Filter_triggered();

    void on_action_Custom_Filter_triggered();

    void on_action_Pseudocolor_triggered();

    void on_action_Save_triggered();

    void on_action_About_Qt_triggered();

    void on_action_About_ImageProcessingKit_triggered();

    void on_action_Addition_triggered();

    void on_action_Subtraction_triggered();

    void on_action_Multiplication_triggered();

    void on_action_Division_triggered();

    void on_action_Negative_triggered();

    void on_action_XOR_triggered();

    void on_action_AND_triggered();

    void on_action_OR_triggered();

    void on_action_FFT_triggered();

    void on_action_IFFT_triggered();

    void on_action_Resize_triggered();

    void on_action_Mirror_triggered();

    void on_action_Flip_triggered();

    void on_action_Inverse_Filter_triggered();

    void on_action_Manual_Threshold_triggered();

    void on_action_Ostu_method_triggered();

    void on_action_Region_Growth_triggered();

    void on_action_Erode_triggered();

    void on_action_Dilate_triggered();

    void on_action_Opening_triggered();

    void on_action_Closing_triggered();

    void on_action_Ideal_High_Pass_Filter_triggered();

    void on_action_Ideal_Low_Pass_Filter_triggered();

    void on_action_Butterworth_Low_Pass_Filter_triggered();

    void on_action_Butterworth_High_Pass_Filter_triggered();

    void on_action_Homomorphic_Filter_triggered();

    void on_action_Motion_Blur_triggered();

    void on_action_Gaussian_Noise_triggered();

    void on_action_Atmospheric_Circulation_Blur_triggered();

    void on_action_Wiener_Filter_triggered();

public slots:
    void showColorValue(const QPointF &position);
    void adjustHsv(const int &h, const float &s, const float &v);
    void linearTransformation(const double &k, const double &b);
    void piecewiseLinearTransformation(const double &r1, const double &s1, const double &r2, const double &s2);
    void averageFilter(const int &size);
    void medianFilter(const int &size);
    void maximumFilter(const int &size);
    void minimumFilter(const int &size);
    void invertFilter(const int &noiseType, const int &D0, const double &variance,
                      const int &length, const int &angle);
    void customFilter(const int &w00, const int &w01, const int &w02,
                      const int &w10, const int &w11, const int &w12,
                      const int &w20, const int &w21, const int &w22);
    void resize(const double &wFactor, const double &hFactor, const int &interpolationType);
    void threshold(const int &threshold);
    void erode(unsigned char structureElement[3][3]);
    void regionGrowth(const QPoint &seed, const int &threshold);
    void dilate(unsigned char structureElement[3][3]);
    void opening(unsigned char structureElement[3][3]);
    void closing(unsigned char structureElement[3][3]);
    void idealHighPassFilter(const int &D0);
    void idealLowPassFilter(const int &D0);
    void butterworthLowPassFilter(const int &Order, const int &D0);
    void butterworthHighPassFilter(const int &Order, const int &D0);
    void homomorphicFilter(const double &gammaL, const double &gammaH, const double &c, const int &D0);
    void motionBlur(const int &length, const int &angle);
    void gaussianNoise(const double &variance);
    void atmosphericCirculationBlur(const double &k);
    void wienerFilter(const int &noiseType,
                      const double &variance,
                      const int &length,
                      const int &angle,
                      const double &k);
    void ifft(const int &ifftType);

private:
    Ui::im *ui;
    QGraphicsScenePlus *inScene, *outScene;
    QPixmap *inPixmap, *outPixmap;
    QGraphicsPixmapItem *inPixmapItem, *outPixmapItem;
    DialogAdjustHsv *dialogAdjustHsv;
    DialogLinearTransform *dialogLinearTransform;
    QString fileName;
    QString saveFileName;
    // result file name used for update out scene
    QString resultFileName;
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
    DialogResize *dlgResize;
    DialogManualThreshold *dlgManualThreshold;
    DialogErode *dlgErode;
    DialogRegionGrowth *dlgRegionGrowth;
    DialogDilate *dlgDilate;
    DialogOpening *dlgOpening;
    DialogClosing *dlgClosing;
    DialogIdealHighPassFilter *dlgIdealHighPassFilter;
    DialogIdealLowPassFilter *dlgIdealLowPassFilter;
    DialogButterworthLowPassFilter *dlgButterworthLowPassFilter;
    DialogButterworthHighPassFilter *dlgButterworthHighPassFilter;
    DialogHomomorphicFilter *dlgHomomorphicFilter;
    DialogMotionBlur *dlgMotionBlur;
    DialogInverseFilter *dlgInverseFilter;
    DialogGaussianNoise *dlgGaussianNoise;
    DialogAtmosphericCirculation *dlgAtmosphericCirculation;
    DialogWienerFilter *dlgWienerFilter;
    DialogIFFT *dlgIFFT;

    CImgList<double> getMotionBlurH(const int &width, const int &height, const int &a, const int &b);
    CImg<double> getPsfKernel(const int &length, const int &angle);
    template<typename T>
    CImgList<double> psfToOtf(const CImg<T> &img, const int &width, const int &height);
    template <typename T>
    bool isGrayscale(const CImg<T> &img);
    template <typename T>
    bool isRGB(const CImg<T> &img);
    bool isBinary(const CImg<int> &img);
    CImg<int> operatorAnd(const CImg<int> &img1, const CImg<int> &img2);
    CImg<int> operatorOr(const CImg<int> &img1, const CImg<int> &img2);
    CImg<int> operatorXor(const CImg<int> &img1, const CImg<int> &img2);
    template <typename T>
    CImgList<T> getConj(const CImgList<T> &img);
    template <typename T>
    CImg<T> fftshift(const CImg<T> &img);
    template <typename T>
    CImgList<T> fftshift(const CImgList<T> &img);
    template <typename T>
    CImg<T> fft(const CImg<T> &img);
    // compute division of two CImgList and other overload
    template<typename T>
    CImgList<T> div(const CImg<T> &img1_real, const CImg<T> &img1_imag,
                    const CImg<T> &img2_real, const CImg<T> &img2_imag);
    template<typename T>
    CImgList<T> div(const CImgList<T> &img1, const CImgList<T> &img2);
    template<typename T>
    CImgList<T> div(const CImgList<T> &img1, const CImgList<T> &img2, const int &D0);
    // compute multiplication of two CImgList and other overload
    template<typename T>
    CImgList<T> mul(const CImg<T> &img1_real, const CImg<T> &img1_imag,
                    const CImg<T> &img2_real, const CImg<T> &img2_imag);
    template<typename T>
    CImgList<T> mul(const CImgList<T> &img1, const CImgList<T> &img2);
    template<typename T>
    CImgList<T> add(const CImgList<T> &img1, const std::complex<T> &val);
    // compute magnitude
    CImg<double> magnitude(const CImgList<double> &img);
    // check if point inside img
    template <typename T>
    bool isInsideImage(const QPoint &point, const CImg<T> &img);
    // keep only magnitude part, and set phase to 1
    template<typename T>
    CImgList<T> keepMagnitude(const CImgList<T> &img);
    // keep only phase part, and set magnitude to 1
    template<typename T>
    CImgList<T> keepPhase(const CImgList<T> &img);
    // image formats supported by Qt
    // one might get all the image formats supported by Qt by:
    // qDebug() << QImageReader::supportedImageFormats();
    QString imageFormat = tr("All Images (*.bmp *.cur *.gif *.icns *.ico *.jp2 *.jpeg *.jpg *.mng *.pbm *.pgm *.png *.ppm *.svg *.svgz *.tga *.tif *.tiff *.wbmp *.webp *.xbm *.xpm);;");
};

#endif // IM_H
