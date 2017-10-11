#ifndef IM_H
#define IM_H

#include <QMainWindow>

namespace Ui {
class im;
}

class im : public QMainWindow
{
    Q_OBJECT

public:
    explicit im(QWidget *parent = 0);
    ~im();

private:
    Ui::im *ui;
};

#endif // IM_H
