#include "dialogminimumfilter.h"
#include "ui_dialogminimumfilter.h"

DialogMinimumFilter::DialogMinimumFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMinimumFilter)
{
    ui->setupUi(this);
}

DialogMinimumFilter::~DialogMinimumFilter()
{
    delete ui;
}

void DialogMinimumFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxFilterSize->value());
}
