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
    float sliderRange = 100.0f;
    float lambdaRange = 4.0f;

    s = ui->horizontalSlider_S->value()/sliderRange*lambdaRange;
    v = ui->horizontalSlider_V->value()/sliderRange*lambdaRange;

    emit sendHsvData(h, s, v);
}

void DialogAdjustHsv::on_horizontalSlider_H_valueChanged(int value)
{
    ui->label_H_Value->setText(tr("%1").arg(value));
}

void DialogAdjustHsv::on_horizontalSlider_S_valueChanged(int value)
{
    // coefficient lambda range (0, 4.0)
    // slider range (0, 100)
    // so lambda = value/sliderRange*lambdaRange
    // one may change sliderRange & lambdaRange to one's need
    float sliderRange = 100.0f;
    float lambdaRange = 4.0f;
    float lambda = value/sliderRange*lambdaRange;

    ui->label_S_Value->setText(QString::number(lambda));
}

void DialogAdjustHsv::on_horizontalSlider_V_valueChanged(int value)
{
    // same as S's coefficient lambda range
    float sliderRange = 100.0f;
    float lambdaRange = 4.0f;
    float lambda = value/sliderRange*lambdaRange;

    ui->label_V_Value->setText(QString::number(lambda));
}
