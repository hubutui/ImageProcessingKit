#ifndef DIALOGMEDIANFILTER_H
#define DIALOGMEDIANFILTER_H

#include <QDialog>

namespace Ui {
class DialogMedianFilter;
}

class DialogMedianFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMedianFilter(QWidget *parent = 0);
    ~DialogMedianFilter();

signals:
    void sendData(const int &size);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogMedianFilter *ui;
};

#endif // DIALOGMEDIANFILTER_H
