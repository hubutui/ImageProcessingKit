#include "dialogifft.h"
#include "ui_dialogifft.h"

DialogIFFT::DialogIFFT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIFFT)
{
    ui->setupUi(this);
}

DialogIFFT::~DialogIFFT()
{
    delete ui;
}

void DialogIFFT::on_buttonBox_accepted()
{
    int result = 0;

    if (ui->radioButtonMagnitudeAndPhase->isChecked()) {
        result = 0;
    } else if (ui->radioButtonMagnitude->isChecked()) {
        result = 1;
    } else if (ui->radioButtonPhase->isChecked()) {
        result = 2;
    } else {
        result = 0;
    }
    emit sendData(result);
}
