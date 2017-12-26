#include "dialogmanualthreshold.h"
#include "ui_dialogmanualthreshold.h"

DialogManualThreshold::DialogManualThreshold(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManualThreshold)
{
    ui->setupUi(this);
}

DialogManualThreshold::~DialogManualThreshold()
{
    delete ui;
}

void DialogManualThreshold::on_buttonBox_accepted()
{
    emit sendData(ui->horizontalSlider->value());
}

void DialogManualThreshold::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(tr("Threshold: %1").arg(value));
}
