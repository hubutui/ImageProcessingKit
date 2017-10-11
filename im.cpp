#include "im.h"
#include "ui_im.h"

im::im(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::im)
{
    ui->setupUi(this);
}

im::~im()
{
    delete ui;
}
