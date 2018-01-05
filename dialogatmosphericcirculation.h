#ifndef DIALOGATMOSPHERICCIRCULATION_H
#define DIALOGATMOSPHERICCIRCULATION_H

#include <QDialog>

namespace Ui {
class DialogAtmosphericCirculation;
}

class DialogAtmosphericCirculation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAtmosphericCirculation(QWidget *parent = 0);
    ~DialogAtmosphericCirculation();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(const double &k);

private:
    Ui::DialogAtmosphericCirculation *ui;
};

#endif // DIALOGATMOSPHERICCIRCULATION_H
