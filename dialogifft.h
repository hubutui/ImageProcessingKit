#ifndef DIALOGIFFT_H
#define DIALOGIFFT_H

#include <QDialog>

namespace Ui {
class DialogIFFT;
}

class DialogIFFT : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIFFT(QWidget *parent = 0);
    ~DialogIFFT();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const int &IfftType);

private:
    Ui::DialogIFFT *ui;
};

#endif // DIALOGIFFT_H
