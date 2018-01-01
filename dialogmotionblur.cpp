#include "dialogmotionblur.h"
#include "ui_dialogmotionblur.h"

DialogMotionBlur::DialogMotionBlur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMotionBlur)
{
    ui->setupUi(this);
}

DialogMotionBlur::~DialogMotionBlur()
{
    delete ui;
}

void DialogMotionBlur::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxLength->value(), ui->spinBoxAngle->value());
}
