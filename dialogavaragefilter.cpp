#include "dialogavaragefilter.h"
#include "ui_dialogavaragefilter.h"

DialogAvarageFilter::DialogAvarageFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAvarageFilter)
{
    ui->setupUi(this);
}

DialogAvarageFilter::~DialogAvarageFilter()
{
    delete ui;
}

void DialogAvarageFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxFilterSize->value());
}
