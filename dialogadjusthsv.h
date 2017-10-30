#ifndef DIALOGADJUSTHSV_H
#define DIALOGADJUSTHSV_H

#include <QDialog>

namespace Ui {
class DialogAdjustHsv;
}

class DialogAdjustHsv : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdjustHsv(QWidget *parent = 0);
    ~DialogAdjustHsv();

private:
    Ui::DialogAdjustHsv *ui;
};

#endif // DIALOGADJUSTHSV_H
