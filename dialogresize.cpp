#include "dialogresize.h"
#include "ui_dialogresize.h"

DialogResize::DialogResize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResize)
{
    ui->setupUi(this);
}

DialogResize::~DialogResize()
{
    delete ui;
}

void DialogResize::on_buttonBox_accepted()
{
    // default interpolation type is Bilinear Interpolation
    int interpolationType = 3;
    if (ui->radioButtonNearest->isChecked()) {
        interpolationType = 1;
    }
    if (ui->radioButtonBilinear->isChecked()) {
        interpolationType = 3;
    }
    if (ui->radioButtonCubic->isChecked()) {
        interpolationType = 5;
    }
    sendData(ui->doubleSpinBoxWidth->value(), ui->doubleSpinBoxHeight->value(), interpolationType);
}
