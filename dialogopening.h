#ifndef DIALOGOPENMORPHOLOGY_H
#define DIALOGOPENMORPHOLOGY_H

#include <QDialog>

namespace Ui {
class DialogOpenMorphology;
}

class DialogOpenMorphology : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOpenMorphology(QWidget *parent = 0);
    ~DialogOpenMorphology();

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
    void sendData(unsigned char stuctureElement[3][3]);
private:
    Ui::DialogOpenMorphology *ui;
};

#endif // DIALOGOPENMORPHOLOGY_H
