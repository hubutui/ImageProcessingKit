#ifndef DIALOGBUTTERWORTHLOWPASSFILTER_H
#define DIALOGBUTTERWORTHLOWPASSFILTER_H

#include <QDialog>

namespace Ui {
class DialogButterworthLowPassFilter;
}

class DialogButterworthLowPassFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogButterworthLowPassFilter(QWidget *parent = 0);
    ~DialogButterworthLowPassFilter();

signals:
    void sendData(const int &Order, const int &D0);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogButterworthLowPassFilter *ui;
};

#endif // DIALOGBUTTERWORTHLOWPASSFILTER_H
