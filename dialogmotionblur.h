#ifndef DIALOGMOTIONBLUR_H
#define DIALOGMOTIONBLUR_H

#include <QDialog>

namespace Ui {
class DialogMotionBlur;
}

class DialogMotionBlur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMotionBlur(QWidget *parent = 0);
    ~DialogMotionBlur();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const int &length, const int &angle);

private:
    Ui::DialogMotionBlur *ui;
};

#endif // DIALOGMOTIONBLUR_H
