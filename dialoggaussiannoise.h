#ifndef DIALOGGAUSSIANNOISE_H
#define DIALOGGAUSSIANNOISE_H

#include <QDialog>

namespace Ui {
class DialogGaussianNoise;
}

class DialogGaussianNoise : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGaussianNoise(QWidget *parent = 0);
    ~DialogGaussianNoise();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const double &variance);
private:
    Ui::DialogGaussianNoise *ui;
};

#endif // DIALOGGAUSSIANNOISE_H
