#ifndef DIALOGLINEARTRANSFORM_H
#define DIALOGLINEARTRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogLinearTransform;
}

class DialogLinearTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLinearTransform(QWidget *parent = 0);
    ~DialogLinearTransform();

signals:
    void sendData(const double &k, const double &b);

private slots:
    void on_doubleSpinBox_k_valueChanged(double arg1);

    void on_doubleSpinBox_b_valueChanged(double arg1);

    void on_buttonBox_accepted();

private:
    Ui::DialogLinearTransform *ui;
    // plot transformation fucntion y = kx + b using qcustomplot.h
    void plotTranformationFunction(const double &k, const double &b);
};

#endif // DIALOGLINEARTRANSFORM_H
