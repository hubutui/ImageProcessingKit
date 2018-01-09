#include "dialogwienerfilter.h"
#include "ui_dialogwienerfilter.h"

DialogWienerFilter::DialogWienerFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWienerFilter)
{
    ui->setupUi(this);
}

DialogWienerFilter::~DialogWienerFilter()
{
    delete ui;
}

void DialogWienerFilter::on_buttonBox_accepted()
{
    int noiseType;

    if (ui->radioButtonNoNoise->isChecked()) {
        noiseType = 0;
    } else if (ui->radioButtonGaussianNoise->isChecked()) {
        noiseType = 1;
    }

    emit sendData(noiseType,
                  ui->doubleSpinBoxVariance->value(),
                  ui->spinBoxLength->value(),
                  ui->spinBoxAngle->value(),
                  ui->doubleSpinBoxK->value());
}
