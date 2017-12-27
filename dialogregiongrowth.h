#ifndef DIALOGREGIONGROWTH_H
#define DIALOGREGIONGROWTH_H

#include <QDialog>

namespace Ui {
class DialogRegionGrowth;
}

class DialogRegionGrowth : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegionGrowth(QWidget *parent = 0);
    ~DialogRegionGrowth();

signals:
    void sendData(const QPoint &seedCoord, const int &threshold);

public slots:
    void setSeedCoord(const QPoint &pos);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogRegionGrowth *ui;
    QPoint seedCoord;
};

#endif // DIALOGREGIONGROWTH_H
