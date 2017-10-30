#include "im.h"
#include "ui_im.h"
#include <QDebug>
#include <QColor>
#include <QRgb>
#include <algorithm>

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

    // TODO:
    // initialize a 512x512 white pixmap
    // and add to scene
    // but it seems not work
    inPixmap = new QPixmap(512, 512);
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

        outPixmap->load(imagePath);
        outPixmapItem = outScene->addPixmap(*outPixmap);
        outScene->setSceneRect(QRectF(outPixmap->rect()));

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

    cimg_forXY(img, x, y) {
        img(x, y, 0) = std::fmod(img(x, y, 0) + h, 360);

        if (s > 0) {
            img(x, y, 1) = std::max(img(x, y, 1)*s, 1.0f);
        } else {
            img(x, y, 1) /= -s;
        }

        if (v > 0) {
            img(x, y, 1) = std::max(img(x, y, 1)*v, 1.0f);
        } else {
            img(x, y, 1) /= -h;
        }
    }

    img.save_png("tmp.png");
}

void im::setFileName(const QString &fileName)
{
    this->fileName = fileName;
}

void im::on_actionAdjust_HSV_triggered()
{
    dialogAdjustHsv = new DialogAdjustHsv;
    dialogAdjustHsv->setModal(true);
    dialogAdjustHsv->show();

    connect(dialogAdjustHsv, SIGNAL(sendHsvData(int, float, float)), this, SLOT(adjustHsv(int, float, float)));
}
