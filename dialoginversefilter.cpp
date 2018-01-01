#include "dialoginversefilter.h"
#include "ui_dialoginversefilter.h"

DialogInverseFilter::DialogInverseFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInverseFilter)
{
    ui->setupUi(this);
}

DialogInverseFilter::~DialogInverseFilter()
{
    delete ui;
}

// noiseType: 0 -> no noise, 1 -> gaussian noise
void DialogInverseFilter::on_buttonBox_accepted()
{
    int noiseType = 0;

    if (ui->radioButtonGaussianNoise->isChecked()) {
        noiseType = 1;
    }

    emit sendData(noiseType,
                  ui->spinBoxCutoffFrequency->value(),
                  ui->doubleSpinBoxVariance->value(),
                  ui->spinBoxLength->value(),
                  ui->spinBoxAngle->value());
}
