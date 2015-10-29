#include "drawdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    drawDemo w;
    w.show();

    return a.exec();
}
