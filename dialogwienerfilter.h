#ifndef DIALOGWIENERFILTER_H
#define DIALOGWIENERFILTER_H

#include <QDialog>

namespace Ui {
class DialogWienerFilter;
}

class DialogWienerFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWienerFilter(QWidget *parent = 0);
    ~DialogWienerFilter();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const int &noiseType,
                  const double &variance,
                  const int &length,
                  const int &angle,
                  const double &k);

private:
    Ui::DialogWienerFilter *ui;
};

#endif // DIALOGWIENERFILTER_H
