#ifndef DIALOGBUTTERWORTHHIGHPASSFILTER_H
#define DIALOGBUTTERWORTHHIGHPASSFILTER_H

#include <QDialog>

namespace Ui {
class DialogButterworthHighPassFilter;
}

class DialogButterworthHighPassFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogButterworthHighPassFilter(QWidget *parent = 0);
    ~DialogButterworthHighPassFilter();

signals:
    void sendData(const int &Order, const int &D0);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogButterworthHighPassFilter *ui;
};

#endif // DIALOGBUTTERWORTHHIGHPASSFILTER_H
