#ifndef DIALOGMINIMUMFILTER_H
#define DIALOGMINIMUMFILTER_H

#include <QDialog>

namespace Ui {
class DialogMinimumFilter;
}

class DialogMinimumFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMinimumFilter(QWidget *parent = 0);
    ~DialogMinimumFilter();

signals:
    void sendData(const int &size);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogMinimumFilter *ui;
};

#endif // DIALOGMINIMUMFILTER_H
