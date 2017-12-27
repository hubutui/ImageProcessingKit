#include "dialogopening.h"
#include "ui_dialogopening.h"

DialogOpenMorphology::DialogOpenMorphology(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpenMorphology)
{
    ui->setupUi(this);
}

DialogOpenMorphology::~DialogOpenMorphology()
{
    delete ui;
}

void DialogOpenMorphology::on_pushButton00_toggled(bool checked)
{
    if (checked) {
        ui->pushButton00->setText(tr("1"));
    } else {
        ui->pushButton00->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton01_toggled(bool checked)
{
    if (checked) {
        ui->pushButton01->setText(tr("1"));
    } else {
        ui->pushButton01->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton02_toggled(bool checked)
{
    if (checked) {
        ui->pushButton02->setText(tr("1"));
    } else {
        ui->pushButton02->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton10_toggled(bool checked)
{
    if (checked) {
        ui->pushButton10->setText(tr("1"));
    } else {
        ui->pushButton10->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton11_toggled(bool checked)
{
    if (checked) {
        ui->pushButton11->setText(tr("1"));
    } else {
        ui->pushButton11->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton12_toggled(bool checked)
{
    if (checked) {
        ui->pushButton12->setText(tr("1"));
    } else {
        ui->pushButton12->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton20_toggled(bool checked)
{
    if (checked) {
        ui->pushButton20->setText(tr("1"));
    } else {
        ui->pushButton20->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton21_toggled(bool checked)
{
    if (checked) {
        ui->pushButton21->setText(tr("1"));
    } else {
        ui->pushButton21->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_pushButton22_toggled(bool checked)
{
    if (checked) {
        ui->pushButton22->setText(tr("1"));
    } else {
        ui->pushButton22->setText(tr("0"));
    }
}

void DialogOpenMorphology::on_buttonBox_accepted()
{
    unsigned char strutureElement[3][3];

    if (ui->pushButton00->isChecked()) {
        strutureElement[0][0] = 1;
    } else {
        strutureElement[0][0] = 0;
    }
    if (ui->pushButton01->isChecked()) {
        strutureElement[0][1] = 1;
    } else {
        strutureElement[0][1] = 0;
    }
    if (ui->pushButton02->isChecked()) {
        strutureElement[0][2] = 1;
    } else {
        strutureElement[0][2] = 0;
    }
    if (ui->pushButton10->isChecked()) {
        strutureElement[1][0] = 1;
    } else {
        strutureElement[1][0] = 0;
    }
    if (ui->pushButton11->isChecked()) {
        strutureElement[1][1] = 1;
    } else {
        strutureElement[1][1] = 0;
    }
    if (ui->pushButton12->isChecked()) {
        strutureElement[1][2] = 1;
    }
    if (ui->pushButton20->isChecked()) {
        strutureElement[2][0] = 1;
    } else {
        strutureElement[2][0] = 0;
    }
    if (ui->pushButton21->isChecked()) {
        strutureElement[2][1] = 1;
    } else {
        strutureElement[2][1] = 0;
    }
    if (ui->pushButton22->isChecked()) {
        strutureElement[2][2] = 1;
    } else {
        strutureElement[2][2] = 0;
    }

    emit sendData(strutureElement);
}
