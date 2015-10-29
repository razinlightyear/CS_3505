// Andrew Emrazian -- October 18 2015
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    ui->lcdNumber->display("00:00:00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Method connected to the timer. Used to update the
 * lcd number text.
 */
void MainWindow::showTime()
{
    // Get the number of total number of units
    int milliseconds = ElapsedTime.elapsed();
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    int hours = minutes / 60;
    // Chop off any higher units
    milliseconds %= 1000;
    seconds %= 60;
    minutes %= 60;
    // Qtime has a handy QString method for time.
    QTime elapsed_time(hours, minutes, seconds, milliseconds);
    QString time_text = elapsed_time.toString("mm:ss:zzz");
    ui->lcdNumber->display(time_text.remove(8,1));
}

void MainWindow::on_startStop_clicked()
{
    if(ui->startStop->text() == "Start")
    {
        timer->start(10); // Set the timer to call showTime every hundredth of a second.
        ElapsedTime.start();
        showTime();
        ui->startStop->setText("Stop");
    }
    else
    {
        timer->stop();
        ui->startStop->setText("Start");
    }
}
