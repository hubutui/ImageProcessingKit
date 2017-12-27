#include "dialogbutterworthlowpassfilter.h"
#include "ui_dialogbutterworthlowpassfilter.h"

DialogButterworthLowPassFilter::DialogButterworthLowPassFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogButterworthLowPassFilter)
{
    ui->setupUi(this);
}

DialogButterworthLowPassFilter::~DialogButterworthLowPassFilter()
{
    delete ui;
}

void DialogButterworthLowPassFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxOrder->value(), ui->spinBoxFrequency->value());
}
