#ifndef DIALOGLINEARTRANSFORM_H
#define DIALOGLINEARTRANSFORM_H

#include <QDialog>

namespace Ui {
class DialogLinearTransform;
}

class DialogLinearTransform : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLinearTransform(QWidget *parent = 0);
    ~DialogLinearTransform();

private:
    Ui::DialogLinearTransform *ui;
};

#endif // DIALOGLINEARTRANSFORM_H
