#ifndef DIALOGINVERSEFILTER_H
#define DIALOGINVERSEFILTER_H

#include <QDialog>

namespace Ui {
class DialogInverseFilter;
}

class DialogInverseFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInverseFilter(QWidget *parent = 0);
    ~DialogInverseFilter();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const int &noiseType, const int &D0, const double &variance,
                  const int &length, const int &angle);

private:
    Ui::DialogInverseFilter *ui;
};

#endif // DIALOGINVERSEFILTER_H
