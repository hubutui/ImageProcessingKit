#include "im.h"
#include "ui_im.h"
#include <QDebug>
#include <QColor>
#include <QRgb>

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

    connect(inScene, SIGNAL(sendCoord(const QPointF&)), this, SLOT(showColorValue(const QPointF&)));

}

im::~im()
{
    delete ui;
}

// 清除图像
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

        // 清除之前显示的图片，然后再显示
        cleanImage();

        // 显示图片
        inPixmap.load(imagePath);
        inPixmapItem = inScene->addPixmap(inPixmap);
        outScene->setSceneRect(QRectF(inPixmap.rect()));

        outPixmap.load(imagePath);
        outPixmapItem = outScene->addPixmap(outPixmap);
        outScene->setSceneRect(QRectF(outPixmap.rect()));
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
    QRgb rgbValue = inPixmap.toImage().pixel(pixel);
    QColor color(rgbValue);
    int gray = qGray(rgbValue);
    QRect rect = inPixmap.rect();
    if (rect.contains(pixel)) {
        ui->label_coord->setText(tr("coord: %1, %2").arg(pixel.x()).arg(pixel.y()));
        ui->label_color_value->setText(tr("R: %1\tG: %2\tB: %3\tgray: %4").arg(color.red()).arg(color.green()).arg(color.blue()).arg(gray));
    }
}
