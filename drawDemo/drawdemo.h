#ifndef DRAWDEMO_H
#define DRAWDEMO_H

#include <QWidget>

namespace Ui {
class drawDemo;
}

class drawDemo : public QWidget
{
    Q_OBJECT

public:
    explicit drawDemo(QWidget *parent = 0);
    ~drawDemo();

private:
    Ui::drawDemo *ui;
};

#endif // DRAWDEMO_H
