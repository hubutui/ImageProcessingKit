#include "dialoglineartransform.h"
#include "ui_dialoglineartransform.h"
#include <qcustomplot.h>

DialogLinearTransform::DialogLinearTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLinearTransform)
{
    ui->setupUi(this);
}

DialogLinearTransform::~DialogLinearTransform()
{
    delete ui;
}
