#ifndef DIALOGCUSTOMFILTER_H
#define DIALOGCUSTOMFILTER_H

#include <QDialog>

namespace Ui {
class DialogCustomFilter;
}

class DialogCustomFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCustomFilter(QWidget *parent = 0);
    ~DialogCustomFilter();

signals:
    void sendData(const int &w00, const int &w01, const int &w02,
                  const int &w10, const int &w11, const int &w12,
                  const int &w20, const int &w21, const int &w22);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogCustomFilter *ui;
};

#endif // DIALOGCUSTOMFILTER_H
