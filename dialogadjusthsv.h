#ifndef DIALOGADJUSTHSV_H
#define DIALOGADJUSTHSV_H

#include <QDialog>

namespace Ui {
class DialogAdjustHsv;
}

class DialogAdjustHsv : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdjustHsv(QWidget *parent = 0);
    ~DialogAdjustHsv();

private:
    Ui::DialogAdjustHsv *ui;

signals:
    void sendHsvData(const int &h, const float &s, const float &v);

private slots:
    void on_buttonBox_accepted();
    void on_horizontalSlider_H_valueChanged(int value);
    void on_horizontalSlider_S_valueChanged(int value);
    void on_horizontalSlider_V_valueChanged(int value);
};

#endif // DIALOGADJUSTHSV_H
