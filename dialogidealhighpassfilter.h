#ifndef DIALOGIDEALHIGHPASSFILTER_H
#define DIALOGIDEALHIGHPASSFILTER_H

#include <QDialog>

namespace Ui {
class DialogIdealHighPassFilter;
}

class DialogIdealHighPassFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIdealHighPassFilter(QWidget *parent = 0);
    ~DialogIdealHighPassFilter();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const int &D0);

private:
    Ui::DialogIdealHighPassFilter *ui;
};

#endif // DIALOGIDEALHIGHPASSFILTER_H
