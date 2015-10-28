#include "pixmap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixMap w;
    w.show();

    return a.exec();
}
