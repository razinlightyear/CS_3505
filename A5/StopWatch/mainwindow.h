// Andrew Emrazian -- October 18 2015
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showTime();             // Update the lcd number text
    void on_startStop_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QTime ElapsedTime;
};

#endif // MAINWINDOW_H
