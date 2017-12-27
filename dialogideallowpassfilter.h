#ifndef DIALOGIDEALLOWPASSFILTER_H
#define DIALOGIDEALLOWPASSFILTER_H

#include <QDialog>

namespace Ui {
class DialogIdealLowPassFilter;
}

class DialogIdealLowPassFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIdealLowPassFilter(QWidget *parent = 0);
    ~DialogIdealLowPassFilter();

signals:
    void sendData(const int &D0);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogIdealLowPassFilter *ui;
};

#endif // DIALOGIDEALLOWPASSFILTER_H
