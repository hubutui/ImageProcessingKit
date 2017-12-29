#include "dialoghomomorphicfilter.h"
#include "ui_dialoghomomorphicfilter.h"

DialogHomomorphicFilter::DialogHomomorphicFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHomomorphicFilter)
{
    ui->setupUi(this);
}

DialogHomomorphicFilter::~DialogHomomorphicFilter()
{
    delete ui;
}

void DialogHomomorphicFilter::on_buttonBox_accepted()
{
    emit sendData(ui->doubleSpinBoxGammaL->value(),
                  ui->doubleSpinBoxGammaH->value(),
                  ui->doubleSpinBoxC->value(),
                  ui->spinBoxFrequency->value());
}
