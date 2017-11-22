#include "dialogmedianfilter.h"
#include "ui_dialogmedianfilter.h"

DialogMedianFilter::DialogMedianFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMedianFilter)
{
    ui->setupUi(this);
}

DialogMedianFilter::~DialogMedianFilter()
{
    delete ui;
}

void DialogMedianFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxFilterSize->value());
}
