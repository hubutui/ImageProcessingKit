#include "dialogatmosphericcirculation.h"
#include "ui_dialogatmosphericcirculation.h"

DialogAtmosphericCirculation::DialogAtmosphericCirculation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAtmosphericCirculation)
{
    ui->setupUi(this);
}

DialogAtmosphericCirculation::~DialogAtmosphericCirculation()
{
    delete ui;
}

void DialogAtmosphericCirculation::on_buttonBox_accepted()
{
    emit sendData(ui->doubleSpinBoxFactor->value());
}
