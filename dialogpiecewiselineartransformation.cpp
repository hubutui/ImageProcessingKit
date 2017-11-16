#include "dialogpiecewiselineartransformation.h"
#include "ui_dialogpiecewiselineartransformation.h"
#include <QDebug>

DialogPiecewiseLinearTransformation::DialogPiecewiseLinearTransformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPiecewiseLinearTransformation)
{
    ui->setupUi(this);
    plotTransformationFunction(ui->spinBoxR1->value(), ui->spinBoxS1->value(), ui->spinBoxR2->value(), ui->spinBoxS2->value());
}

DialogPiecewiseLinearTransformation::~DialogPiecewiseLinearTransformation()
{
    delete ui;
}

void DialogPiecewiseLinearTransformation::plotTransformationFunction(const double &r1, const double &s1, const double &r2, const double &s2)
{
    // generate some data:
    QVector<double> x(25501), y(25501);
    for (int i = 0; i < 25501; ++i)
    {
      x[i] = i + 0.01;

      if (x[i] < r1) {
          y[i] = s1/r1*x[i];
          qDebug() << y[i] << endl;
      } else if (x[i] < r2) {
          y[i] = (s2 - s1)/(r2 - r1)*(x[i] - r1) + s1;
      } else {
          y[i] = (255 - s2)/(255 - r2)*(x[i] - r2) + s2;
      }
    }
    // create graph and assign data to it:
    ui->transformationFunctionPlot->addGraph();
    ui->transformationFunctionPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->transformationFunctionPlot->xAxis->setLabel("r");
    ui->transformationFunctionPlot->yAxis->setLabel("s");
    // set axes ranges, so we see all data:
    ui->transformationFunctionPlot->xAxis->setRange(0, 255);
    ui->transformationFunctionPlot->yAxis->setRange(0, 255);
    ui->transformationFunctionPlot->replot();

}

void DialogPiecewiseLinearTransformation::on_spinBoxR1_valueChanged(int arg1)
{
    plotTransformationFunction(arg1, ui->spinBoxS1->value(), ui->spinBoxR2->value(), ui->spinBoxS2->value());
}

void DialogPiecewiseLinearTransformation::on_spinBoxS1_valueChanged(int arg1)
{
    plotTransformationFunction(ui->spinBoxR1->value(), arg1, ui->spinBoxR2->value(), ui->spinBoxS2->value());
}

void DialogPiecewiseLinearTransformation::on_spinBoxR2_valueChanged(int arg1)
{
    plotTransformationFunction(ui->spinBoxR1->value(), ui->spinBoxS1->value(), arg1, ui->spinBoxS2->value());
}

void DialogPiecewiseLinearTransformation::on_spinBoxS2_valueChanged(int arg1)
{
    plotTransformationFunction(ui->spinBoxR1->value(), ui->spinBoxS1->value(), ui->spinBoxR2->value(), arg1);
}

void DialogPiecewiseLinearTransformation::on_buttonBox_accepted()
{
    emit sendData(ui->spinBoxR1->value(), ui->spinBoxS1->value(), ui->spinBoxR2->value(), ui->spinBoxS2->value());
}
