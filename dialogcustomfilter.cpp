#include "dialogcustomfilter.h"
#include "ui_dialogcustomfilter.h"

DialogCustomFilter::DialogCustomFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCustomFilter)
{
    ui->setupUi(this);
}

DialogCustomFilter::~DialogCustomFilter()
{
    delete ui;
}

void DialogCustomFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBox_w00->value(), ui->spinBox_w01->value(), ui->spinBox_w02->value(),
                  ui->spinBox_w10->value(), ui->spinBox_w11->value(), ui->spinBox_w12->value(),
                  ui->spinBox_w20->value(), ui->spinBox_w21->value(), ui->spinBox_w22->value());
}
