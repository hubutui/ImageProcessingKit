#include "dialogadjusthsv.h"
#include "ui_dialogadjusthsv.h"

DialogAdjustHsv::DialogAdjustHsv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdjustHsv)
{
    ui->setupUi(this);
}

DialogAdjustHsv::~DialogAdjustHsv()
{
    delete ui;
}
