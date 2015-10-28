#include "pixmap.h"
#include "ui_pixmap.h"

PixMap::PixMap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PixMap)
{
    ui->setupUi(this);
}

PixMap::~PixMap()
{
    delete ui;
}
