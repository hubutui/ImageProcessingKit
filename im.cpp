#include "im.h"
#include "ui_im.h"
#include <QDebug>
#include <QColor>
#include <QRgb>
#include <algorithm>
#include <qcustomplot.h>

im::im(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::im)
{
    ui->setupUi(this);

    // TOTO:
    // set mouse tracking, by default, mouse tracking is only enable the mouse button is pressed
    // however, I could not figure out why it doesn't work here.
    if (!hasMouseTracking()) {
        setMouseTracking(true);
    }

    // create new QGraphicsScene obeject, and binding to ui widget.
    inScene = new QGraphicsScenePlus;
    outScene = new QGraphicsScenePlus;
    ui->graphicsView_in->setScene(inScene);
    ui->graphicsView_out->setScene(outScene);

    // initialize a 1x1 white pixmap
    // and add to scene
    // so everything looks great
    inPixmap = new QPixmap(1, 1);
    inPixmap->fill();
    outPixmap = new QPixmap(*inPixmap);
    inPixmapItem = inScene->addPixmap(*inPixmap);
    outPixmapItem = outScene->addPixmap(*outPixmap);

    // connect signal and slot
    // once coord change, we emit a sinal from mouseMoveEvent
    // and then a slot is called to show the color value
    connect(inScene, SIGNAL(coordChanged(const QPointF&)), this, SLOT(showColorValue(const QPointF&)));
}

im::~im()
{
    delete ui;
}

// clear image diplayed in scene
void im::cleanImage()
{
    inScene->clear();
    outScene->clear();
}

void im::on_action_Quit_triggered()
{
    QApplication::quit();
}

void im::on_action_Open_triggered()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath(), tr("All Images (*.bmp *.jpg *.jpeg *.png *.tif *.tiff);;"));

    if (!imagePath.isEmpty()) {
        QFile file(imagePath);

        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to read image!"));
            return;
        }

        // clear previouly showed image
        cleanImage();

        // show image
        inPixmap->load(imagePath);
        inPixmapItem = inScene->addPixmap(*inPixmap);
        inScene->setSceneRect(QRectF(inPixmap->rect()));

//  considering load image to outScene?
//        outPixmap->load(imagePath);
//        outPixmapItem = outScene->addPixmap(*outPixmap);
//        outScene->setSceneRect(QRectF(outPixmap->rect()));

        // save fileName for later use
        setFileName(imagePath);
    }
}

void im::on_actionSave_as_triggered()
{
    QString savePath = QFileDialog::getSaveFileName(this, tr("Save image"), QDir::homePath(), tr("All Images (*.bmp *.jpg *.jpeg *.png *.tif *.tiff);;"));

    if (!savePath.isEmpty()) {
        QFile file(savePath);

        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to save image!"));
            return;
        }

        outPixmapItem->pixmap().save(savePath);
    }
}

void im::on_actionClose_triggered()
{
    cleanImage();
}

void im::showColorValue(const QPointF &position)
{
    // map position from scene to current item
    QPointF pos = inPixmapItem->mapFromScene(position);
	QPoint pixel;
	pixel.setX(int(pos.x()));
	pixel.setY(int(pos.y()));
    QRgb rgbValue = inPixmap->toImage().pixel(pixel);
    QColor color(rgbValue);
    int gray = qGray(rgbValue);
    QRect rect = inPixmap->rect();
    if (rect.contains(pixel)) {
        ui->label_coord->setText(tr("coord: %1, %2").arg(pixel.x()).arg(pixel.y()));
        ui->label_color_value->setText(tr("R: %1\tG: %2\tB: %3\tgray: %4").arg(color.red()).arg(color.green()).arg(color.blue()).arg(gray));
    }
}

void im::adjustHsv(const int &h, const float &s, const float &v)
{
    CImg<float> img(fileName.toStdString().data());
    img.RGBtoHSV();
    qDebug() << "h = " << h << ", s = " << s << ", v = " << v << endl;

    cimg_forXY(img, x, y) {
        img(x, y, 0) = std::fmod(img(x, y, 0) + h, 360);
        img(x, y, 1) = s*img(x, y, 1);
        img(x, y, 2) = v*img(x, y, 2);
    }

    img.HSVtoRGB().save_png("tmp.png");
    updateOutScene("tmp.png");
}

void im::linearTransformation(const double &k, const double &b)
{
    CImg<double> img(fileName.toStdString().data());

    cimg_forXY(img, x, y) {
        img(x, y, 0) = img(x, y, 0)*k + b;
    }

    img.save_png("tmp.png");
    updateOutScene("tmp.png");
}

void im::piecewiseLinearTransformation(const double &r1, const double &s1, const double &r2, const double &s2)
{
    CImg<double> img(fileName.toStdString().data());

    cimg_forXY(img, x, y) {
        if (img(x, y) < r1) {
            img(x, y) = s1/r1*img(x, y);
        } else if (img(x, y) < r2) {
            img(x, y) = (s2 - s1)/(r2 - r1)*(img(x, y) - r1) + s1;
        } else {
            img(x, y) = (255 - s2)/(255 - r1)*(img(x, y) - r2) + s2;
        }
    }

    img.save_png("tmp.png");
    updateOutScene("tmp.png");

}

void im::averageFilter(const int &size)
{
    CImg<float> img(fileName.toStdString().data());
    CImg<float> kernel(size, size, 1, 1, 1.0f/size/size);

    CImg<float> dest = img.convolve(kernel);
    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}

void im::medianFilter(const int &size)
{
    CImg<float> img(fileName.toStdString().data());
    img.blur_median(size);
    img.save_png("tmp.png");

    updateOutScene("tmp.png");
}

// maximum filter
// with size x size window
// just slide window over the image
// replace the middle pixel's intensity with
// maximum of the window
void im::maximumFilter(const int &size)
{
    CImg<unsigned char> img(fileName.toStdString().data());
    // slide window, just like a kernel, but not for convolve
    // so it's not a good idea to name it kernel
    // use window instead
    CImg<unsigned char> window(size, size);
    CImg<unsigned char> dest(img);

    cimg_forXY(img, x, y) {
        cimg_forXY(window, u, v) {
            window(u, v) = img(x + u, y + v);
        }
        // (x + (size - 1)/2, y + (size - 1)/2) is the middle pos
        // of the slide window
        // check if it's out of array boundary
        if (x + (size - 1)/2 < img.width() && y + (size - 1)/2 < img.height()) {
            dest(x, y) = window.max();
            qDebug() << dest(x, y) << endl;
        }
    }

    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}

// minimum filter, just like maximum filter
// but use minimum instead of maximum
void im::minimumFilter(const int &size)
{
    CImg<unsigned char> img(fileName.toStdString().data());
    CImg<unsigned char> window(size, size, 1, 1, 255);
    CImg<unsigned char> dest(img);

    cimg_forXY(img, x, y) {
        cimg_forXY(window, u, v) {
            window(u, v) = img(x + u, y + v);
        }
        if (x + (size - 1)/2 < img.width() && y + (size - 1)/2 < img.height()) {
            dest(x + (size - 1)/2, y + (size - 1)/2) = window.min();
        }
    }

    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}

void im::customFilter(const int &w00, const int &w01, const int &w02, const int &w10, const int &w11, const int &w12, const int &w20, const int &w21, const int &w22)
{
    CImg<float> img(fileName.toStdString().data());
    int size = 3;
    CImg<float> kernel(size, size, 1, 1,
                       w00, w01, w02,
                       w10, w11, w12,
                       w20, w21, w22);
    // if sum of all pixels in kernel is not zero
    // make sure it's 1
    if (!(kernel.sum() < DBL_EPSILON)) {
        kernel = kernel/(size*size);
    }

    img.convolve(kernel);
    img.save_png("tmp.png");

    updateOutScene("tmp.png");
}

void im::setFileName(const QString &fileName)
{
    this->fileName = fileName;
}

void im::updateOutScene(const QString &fileName)
{
    qDebug() << "repaint out image." << endl;
    outScene->clear();
    outPixmap->load(fileName);
    outPixmapItem = outScene->addPixmap(*outPixmap);
    outScene->setSceneRect(QRectF(outPixmap->rect()));
}

// convert RGB to gray scale
// note the formular here assume that
// RGB weight differs.
int im::rgbToGray(const int &r, const int &g, const int &b)
{
    return (r * 11 + g * 16 + b * 5)/32;
}

void im::on_actionAdjust_HSV_triggered()
{
    dialogAdjustHsv = new DialogAdjustHsv;
    dialogAdjustHsv->setModal(true);
    dialogAdjustHsv->show();

    connect(dialogAdjustHsv, SIGNAL(sendHsvData(int, float, float)), this, SLOT(adjustHsv(int, float, float)));
}

void im::on_action_Grayscale_triggered()
{
    // read RGB file
    CImg<int> img(fileName.toStdString().data());
    // create a gray scale image
    CImg<int> dest(img.width(), img.height());

    // convert RGB to gray scale, store in dest
    cimg_forXY(dest, x, y) {
        dest(x, y) = rgbToGray(img(x, y, 0), img(x, y, 1), img(x, y, 2));
    }

    // save image
    dest.save_png("tmp.png");
    updateOutScene("tmp.png");
}

void im::on_action_Linear_transformation_triggered()
{
    dialogLinearTransform = new DialogLinearTransform;
    dialogLinearTransform->setModal(true);
    dialogLinearTransform->show();

    connect(dialogLinearTransform, SIGNAL(sendData(double,double)), this, SLOT(linearTransformation(double,double)));
}

void im::on_action_Histogram_triggered()
{
    CImg<float> img(fileName.toStdString().data());
    // 计算直方图
    // hist 中保存每个灰度级的像素数量
    CImg<float> hist = img.histogram(255);
    // 直方图窗口标题
    QString title = "Histogram of " + fileName;
    // 新建一个 CImgDisplay 对象用来显示直方图
    CImgDisplay display(800, 600, title.toStdString().data());
    // 直方图显示
    hist.display_graph(display, 3);
}

void im::on_actionHistogram_equalization_triggered()
{
    CImg<unsigned char> img(fileName.toStdString().data());
    CImg<unsigned char> dest = img.get_equalize(256);
    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}

void im::on_actionHistogram_Specication_triggered()
{
    CImg<float> img(fileName.toStdString().data());
    CImg<float> dest(img.width(), img.height());
    float threshold = 128;
    cimg_forXY(img, x, y) {
        if (img(x, y) < threshold)
        {
            dest(x, y) = img(x, y);
        } else {
            dest(x, y) = 0.7 * img(x, y);
        }
    }
    dest.save_png("hist-spec.png");
    CImg<float> hist = dest.histogram(256);
    hist.display_graph(0, 3);

    updateOutScene("hist-spec.png");
}

void im::on_actionPiecewise_linear_transformation_triggered()
{
    dlgPiecewiseLinearTranformation = new DialogPiecewiseLinearTransformation;
    dlgPiecewiseLinearTranformation->setModal(true);
    dlgPiecewiseLinearTranformation->show();

    connect(dlgPiecewiseLinearTranformation, SIGNAL(sendData(double, double, double, double)), this, SLOT(piecewiseLinearTransformation(double, double, double, double)));
}

void im::on_actionAverage_filter_triggered()
{
    dlgAverageFilter = new DialogAvarageFilter;
    dlgAverageFilter->setModal(true);
    dlgAverageFilter->show();

    connect(dlgAverageFilter, SIGNAL(sendData(int)), this, SLOT(averageFilter(int)));
}

void im::on_actionLaplacian_filter_triggered()
{
    CImg<float> img(fileName.toStdString().data());
    CImg<float> dest = img.get_laplacian();
    dest.save_png("laplacian.png");
    dest = img + 0.5*dest;
    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}

void im::on_actionMedian_filter_triggered()
{
    dlgMedianFilter = new DialogMedianFilter;
    dlgMedianFilter->setModal(true);
    dlgMedianFilter->show();

    connect(dlgMedianFilter, SIGNAL(sendData(int)), this, SLOT(medianFilter(int)));
}

void im::on_actionMaximum_filter_triggered()
{
    dlgMaximumFilter = new DialogMaximumFilter;
    dlgMaximumFilter->setModal(true);;
    dlgMaximumFilter->show();

    connect(dlgMaximumFilter, SIGNAL(sendData(int)), this, SLOT(maximumFilter(int)));
}

void im::on_actionMinimum_filter_triggered()
{
    dlgMinimumFilter = new DialogMinimumFilter;
    dlgMinimumFilter->setModal(true);
    dlgMinimumFilter->show();

    connect(dlgMinimumFilter, SIGNAL(sendData(int)), this, SLOT(minimumFilter(int)));

}

void im::on_actionCustomFilter_triggered()
{
    dlgCustomFilter = new DialogCustomFilter;
    dlgCustomFilter->setModal(true);
    dlgCustomFilter->show();

    connect(dlgCustomFilter, SIGNAL(sendData(int,int,int,int,int,int,int,int,int)),
            this, SLOT(customFilter(int,int,int,int,int,int,int,int,int)));
}

void im::on_actionPseudocolor_triggered()
{
    CImg<float> img(fileName.toStdString().data());
    CImg<float> dest(img.width(), img.height(), 1, 3);

    // transformation for R channel
    cimg_forXY(img, x, y) {
        if (img(x, y) < 128) {
            dest(x, y, 0, 0) = 0;
        } else if (img(x, y) < 200) {
            dest(x, y, 0, 0) = 255/128*(img(x, y) - 128);
        } else {
            dest(x, y, 0, 0) = 255;
        }
    }

    // transformation for G channel
    cimg_forXY(img, x, y) {
        if (img(x, y) < 64) {
            dest(x, y, 0, 1) = 255/64*img(x, y);
        } else if (img(x, y) < 200) {
            dest(x, y, 0, 1) = 255;
        } else {
            dest(x, y, 0, 1) = -255/(255 - 200)*(img(x, y) - 200) + 255;
        }
    }

    // transformation for B channel
    cimg_forXY(img, x, y) {
        if (img(x, y) < 64) {
            dest(x, y, 0, 2) = 255;
        } else if (img(x, y) < 128) {
            dest(x, y, 0, 2) = -255/(128 - 64)*(img(x, y) - 64) + 255;
        } else {
            dest(x, y, 0, 2) = 0;
        }
    }

    dest.save_png("tmp.png");

    updateOutScene("tmp.png");
}
