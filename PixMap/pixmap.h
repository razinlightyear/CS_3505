#ifndef PIXMAP_H
#define PIXMAP_H

#include <QMainWindow>

namespace Ui {
class PixMap;
}

class PixMap : public QMainWindow
{
    Q_OBJECT

public:
    explicit PixMap(QWidget *parent = 0);
    ~PixMap();

private:
    Ui::PixMap *ui;
};

#endif // PIXMAP_H
