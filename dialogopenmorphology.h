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

private:
    Ui::DialogOpenMorphology *ui;
};

#endif // DIALOGOPENMORPHOLOGY_H
