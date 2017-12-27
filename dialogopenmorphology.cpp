#include "dialogopenmorphology.h"
#include "ui_dialogopenmorphology.h"

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
