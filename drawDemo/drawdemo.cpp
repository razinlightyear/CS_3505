#include "drawdemo.h"
#include "ui_drawdemo.h"

drawDemo::drawDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawDemo)
{
    ui->setupUi(this);
}

drawDemo::~drawDemo()
{
    delete ui;
}
