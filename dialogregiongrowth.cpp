#include "dialogregiongrowth.h"
#include "ui_dialogregiongrowth.h"
#include <QMessageBox>

DialogRegionGrowth::DialogRegionGrowth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegionGrowth)
{
    ui->setupUi(this);
    seedCoord = QPoint(-1, -1);
}

DialogRegionGrowth::~DialogRegionGrowth()
{
    delete ui;
}

void DialogRegionGrowth::setSeedCoord(const QPoint &pos)
{
    this->seedCoord = pos;
    ui->label_seed_coord->setText(tr("Seed Coord: (%1, %2)").arg(pos.x()).arg(pos.y()));
}

void DialogRegionGrowth::on_buttonBox_accepted()
{
    if (seedCoord == QPoint(-1, -1)) {
        QMessageBox::critical(this, tr("Error!"), tr("Non seed select."));
        return;
    }
    emit sendData(this->seedCoord, ui->spinBox->value());
}
