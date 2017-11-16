#ifndef DIALOGPIECEWISELINEARTRANSFORMATION_H
#define DIALOGPIECEWISELINEARTRANSFORMATION_H

#include <QDialog>

namespace Ui {
class DialogPiecewiseLinearTransformation;
}

class DialogPiecewiseLinearTransformation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPiecewiseLinearTransformation(QWidget *parent = 0);
    ~DialogPiecewiseLinearTransformation();
signals:
    void sendData(const double& r1, const double& s1, const double& r2, const double& s2);
private slots:
    void on_spinBoxR1_valueChanged(int arg1);

    void on_spinBoxS1_valueChanged(int arg1);

    void on_spinBoxR2_valueChanged(int arg1);

    void on_spinBoxS2_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::DialogPiecewiseLinearTransformation *ui;
    void plotTransformationFunction(const double& r1, const double& s1, const double& r2, const double& s2);
};

#endif // DIALOGPIECEWISELINEARTRANSFORMATION_H
