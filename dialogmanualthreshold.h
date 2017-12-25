#ifndef DIALOGMANUALTHRESHOLD_H
#define DIALOGMANUALTHRESHOLD_H

#include <QDialog>

namespace Ui {
class DialogManualThreshold;
}

class DialogManualThreshold : public QDialog
{
    Q_OBJECT

public:
    explicit DialogManualThreshold(QWidget *parent = 0);
    ~DialogManualThreshold();

private slots:
    void on_buttonBox_accepted();

    void on_horizontalSlider_valueChanged(int value);

signals:
    void sendData(const int &threshold);
private:
    Ui::DialogManualThreshold *ui;
};

#endif // DIALOGMANUALTHRESHOLD_H
