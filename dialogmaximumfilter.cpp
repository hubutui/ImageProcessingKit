#include "dialogmaximumfilter.h"
#include "ui_dialogmaximumfilter.h"

DialogMaximumFilter::DialogMaximumFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMaximumFilter)
{
    ui->setupUi(this);
}

DialogMaximumFilter::~DialogMaximumFilter()
{
    delete ui;
}

void DialogMaximumFilter::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxFilterSize->value());
}
