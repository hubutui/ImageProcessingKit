#include "im.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    im w;
    w.show();

    return a.exec();
}
