#include "dialogadjusthsv.h"
#include "ui_dialogadjusthsv.h"
#include <cmath>

DialogAdjustHsv::DialogAdjustHsv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdjustHsv)
{
    ui->setupUi(this);
}

DialogAdjustHsv::~DialogAdjustHsv()
{
    delete ui;
}

void DialogAdjustHsv::on_buttonBox_accepted()
{
    int h = ui->horizontalSlider_H->value();
    qreal s, v;

    s = log(1 + ui->horizontalSlider_S->value());
    v = log(1 + ui->horizontalSlider_V->value());

    emit sendHsvData(h, s, v);
}

void DialogAdjustHsv::on_horizontalSlider_H_valueChanged(int value)
{
    ui->label_H_Value->setText(tr("%1").arg(value));
}

void DialogAdjustHsv::on_horizontalSlider_S_valueChanged(int value)
{
    if (value < 0) {
        ui->label_S_Value->setText(tr("%1").arg(-log(1 - value/16.0f)));
    } else {
        ui->label_S_Value->setText(tr("%1").arg(log(1 + value/16.0f)));
    }
}

void DialogAdjustHsv::on_horizontalSlider_V_valueChanged(int value)
{
    if (value < 0) {
        ui->label_V_Value->setText(tr("%1").arg(-log(1 - value/16.0f)));
    } else {
        ui->label_V_Value->setText(tr("%1").arg(log(1 + value/16.0f)));
    }
}
