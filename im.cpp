#include "im.h"
#include "ui_im.h"
#include "CImg.h"

using namespace cimg_library;

im::im(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::im)
{
    ui->setupUi(this);

    // 初始化 QGraphicsScene，将 UI 中的控件与 im 类中对应的对象联系起来
    inScene = new QGraphicsScene;
    outScene = new QGraphicsScene;
    ui->graphicsView_in->setScene(inScene);
    ui->graphicsView_out->setScene(outScene);

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
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath(), tr("All Images (*.bmp *.jpg *.jpeg *.png *.tif *.tiff);;"));

    if (!imagePath.isEmpty()) {
        QFile file(imagePath);

        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to read image!"));
            return;
        }

        // 清除之前显示的图片，然后再显示
        cleanImage();

        // 显示图片
        QPixmap inPixmap(imagePath);
        inPixmapItem = inScene->addPixmap(inPixmap);
        outScene->setSceneRect(QRectF(inPixmap.rect()));

        QPixmap outPixmap(imagePath);
        outPixmapItem = outScene->addPixmap(outPixmap);
        outScene->setSceneRect(QRectF(outPixmap.rect()));
    }
}

void im::on_actionSave_as_triggered()
{
    QString savePath = QFileDialog::getSaveFileName(this, tr("Save image"), QString(), tr("All Images (*.bmp *.jpg *.jpeg *.png *.tif *.tiff);;"));

    if (!savePath.isEmpty()) {
        QFile file(savePath);

        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to save image!"));
            return;
        }

        outPixmapItem->pixmap().save(savePath);
    }
}
