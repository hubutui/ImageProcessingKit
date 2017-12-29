#include "dialogbutterworthhighpassfilter.h"
#include "ui_dialogbutterworthhighpassfilter.h"

DialogButterworthHighPassFilter::DialogButterworthHighPassFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogButterworthHighPassFilter)
{
    ui->setupUi(this);
}

DialogButterworthHighPassFilter::~DialogButterworthHighPassFilter()
{
    delete ui;
}

void DialogButterworthHighPassFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxOrder->value(), ui->spinBoxFrequency->value());
}
