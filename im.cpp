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
