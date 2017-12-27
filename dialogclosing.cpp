#include "dialogclosing.h"
#include "ui_dialogclosing.h"

DialogClosing::DialogClosing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClosing)
{
    ui->setupUi(this);
}

DialogClosing::~DialogClosing()
{
    delete ui;
}

void DialogClosing::on_pushButton00_toggled(bool checked)
{
    if (checked) {
        ui->pushButton00->setText("1");
    } else {
        ui->pushButton00->setText("0");
    }
}

void DialogClosing::on_pushButton01_toggled(bool checked)
{
    if (checked) {
        ui->pushButton01->setText("1");
    } else {
        ui->pushButton01->setText("0");
    }
}

void DialogClosing::on_pushButton02_toggled(bool checked)
{
    if (checked) {
        ui->pushButton02->setText("1");
    } else {
        ui->pushButton02->setText("0");
    }
}

void DialogClosing::on_pushButton10_toggled(bool checked)
{
    if (checked) {
        ui->pushButton10->setText("1");
    } else {
        ui->pushButton10->setText("0");
    }
}

void DialogClosing::on_pushButton11_toggled(bool checked)
{
    if (checked) {
        ui->pushButton11->setText("1");
    } else {
        ui->pushButton11->setText("0");
    }
}

void DialogClosing::on_pushButton12_toggled(bool checked)
{
    if (checked) {
        ui->pushButton12->setText("1");
    } else {
        ui->pushButton12->setText("0");
    }
}

void DialogClosing::on_pushButton20_toggled(bool checked)
{
    if (checked) {
        ui->pushButton20->setText("1");
    } else {
        ui->pushButton20->setText("0");
    }
}

void DialogClosing::on_pushButton21_toggled(bool checked)
{
    if (checked) {
        ui->pushButton21->setText("1");
    } else {
        ui->pushButton21->setText("0");
    }
}

void DialogClosing::on_pushButton22_toggled(bool checked)
{
    if (checked) {
        ui->pushButton22->setText("1");
    } else {
        ui->pushButton22->setText("0");
    }
}

void DialogClosing::on_buttonBox_accepted()
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
