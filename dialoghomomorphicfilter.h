#ifndef DIALOGHOMOMORPHICFILTER_H
#define DIALOGHOMOMORPHICFILTER_H

#include <QDialog>

namespace Ui {
class DialogHomomorphicFilter;
}

class DialogHomomorphicFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHomomorphicFilter(QWidget *parent = 0);
    ~DialogHomomorphicFilter();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const double &gammaL, const double &gammaH, const double &c, const int &D0);

private:
    Ui::DialogHomomorphicFilter *ui;
};

#endif // DIALOGHOMOMORPHICFILTER_H
