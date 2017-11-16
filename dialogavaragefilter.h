#ifndef DIALOGAVARAGEFILTER_H
#define DIALOGAVARAGEFILTER_H

#include <QDialog>

namespace Ui {
class DialogAvarageFilter;
}

class DialogAvarageFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAvarageFilter(QWidget *parent = 0);
    ~DialogAvarageFilter();

signals:
    void sendData(const int& size);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAvarageFilter *ui;
};

#endif // DIALOGAVARAGEFILTER_H
