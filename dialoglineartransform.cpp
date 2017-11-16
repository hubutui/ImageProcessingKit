#include "dialoglineartransform.h"
#include "ui_dialoglineartransform.h"
#include <qcustomplot.h>

DialogLinearTransform::DialogLinearTransform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLinearTransform)
{
    ui->setupUi(this);

    // plot default transformation function y = kx + b in constructor
    // where k = 1, b = 0
    plotTranformationFunction(1, 0);
}

DialogLinearTransform::~DialogLinearTransform()
{
    delete ui;
}

void DialogLinearTransform::plotTranformationFunction(const double &k, const double &b)
{
    // generate some data:
    QVector<double> x(25501), y(25501);
    for (int i=0; i<25501; ++i)
    {
      x[i] = i + 0.01;
      y[i] = x[i]*k + b;
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

void DialogLinearTransform::on_doubleSpinBox_k_valueChanged(double arg1)
{
    plotTranformationFunction(arg1, ui->doubleSpinBox_b->value());
}

void DialogLinearTransform::on_doubleSpinBox_b_valueChanged(double arg1)
{
    plotTranformationFunction(ui->doubleSpinBox_k->value(), arg1);
}

void DialogLinearTransform::on_buttonBox_accepted()
{
    // send k & b to main window
    emit sendData(ui->doubleSpinBox_k->value(), ui->doubleSpinBox_b->value());
}
