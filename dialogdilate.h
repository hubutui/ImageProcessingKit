#ifndef DIALOGDILATE_H
#define DIALOGDILATE_H

#include <QDialog>

namespace Ui {
class DialogDilate;
}

class DialogDilate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDilate(QWidget *parent = 0);
    ~DialogDilate();

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
    void sendData(unsigned char strutureElement[3][3]);

private:
    Ui::DialogDilate *ui;
};

#endif // DIALOGDILATE_H
