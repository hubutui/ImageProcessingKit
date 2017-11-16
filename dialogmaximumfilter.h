#ifndef DIALOGMAXIMUMFILTER_H
#define DIALOGMAXIMUMFILTER_H

#include <QDialog>

namespace Ui {
class DialogMaximumFilter;
}

class DialogMaximumFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMaximumFilter(QWidget *parent = 0);
    ~DialogMaximumFilter();

signals:
    void sendData(const int &size);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogMaximumFilter *ui;
};

#endif // DIALOGMAXIMUMFILTER_H
