#ifndef DIALOGERODE_H
#define DIALOGERODE_H

#include <QDialog>

namespace Ui {
class DialogErode;
}

class DialogErode : public QDialog
{
    Q_OBJECT

public:
    explicit DialogErode(QWidget *parent = 0);
    ~DialogErode();

private slots:
    void on_pushButton00_toggled(bool checked);

    void on_pushButton01_toggled(bool checked);

    void on_pushButton02_toggled(bool checked);

    void on_pushButton10_toggled(bool checked);

    void on_pushButton11_toggled(bool checked);

    void on_pushButton12_toggled(bool checked);

    void on_pushButton20_toggled(bool checked);

    void on_pushButton21_toggled(bool checked);

    void on_pushButton22_toggled(bool checked);

    void on_buttonBox_accepted();

signals:
    void sendData(unsigned char kernel[3][3]);

private:
    Ui::DialogErode *ui;
};

#endif // DIALOGERODE_H
