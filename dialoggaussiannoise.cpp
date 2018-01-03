#include "dialoggaussiannoise.h"
#include "ui_dialoggaussiannoise.h"

DialogGaussianNoise::DialogGaussianNoise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGaussianNoise)
{
    ui->setupUi(this);
}

DialogGaussianNoise::~DialogGaussianNoise()
{
    delete ui;
}

void DialogGaussianNoise::on_buttonBox_accepted()
{
    emit sendData(ui->doubleSpinBoxVariance->value());
}
