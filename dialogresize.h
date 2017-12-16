#ifndef DIALOGRESIZE_H
#define DIALOGRESIZE_H

#include <QDialog>

namespace Ui {
class DialogResize;
}

class DialogResize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResize(QWidget *parent = 0);
    ~DialogResize();

private:
    Ui::DialogResize *ui;

signals:
    void sendData(const double &wFacotr, const double &hFactor, const int &interpolationType);
private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGRESIZE_H
