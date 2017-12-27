#include "dialogidealhighpassfilter.h"
#include "ui_dialogidealhighpassfilter.h"

DialogIdealHighPassFilter::DialogIdealHighPassFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIdealHighPassFilter)
{
    ui->setupUi(this);
}

DialogIdealHighPassFilter::~DialogIdealHighPassFilter()
{
    delete ui;
}

void DialogIdealHighPassFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBox->value());
}
