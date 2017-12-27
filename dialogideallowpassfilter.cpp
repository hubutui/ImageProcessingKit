#include "dialogideallowpassfilter.h"
#include "ui_dialogideallowpassfilter.h"

DialogIdealLowPassFilter::DialogIdealLowPassFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIdealLowPassFilter)
{
    ui->setupUi(this);
}

DialogIdealLowPassFilter::~DialogIdealLowPassFilter()
{
    delete ui;
}

void DialogIdealLowPassFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBox->value());
}
