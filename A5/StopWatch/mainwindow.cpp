#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QThread> // remove me
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTimer* timer = new QTimer(this);//showTime();
    //connect(timer, SIGNAL(timeout()), this, SLOT(on_startStop_clicked()));
    //timer->start();

    //QTimer* timer = new QTimer(this);//showTime();
    //connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    //timer->start(10);

    //QTime startTime = QTime::currentTime();
    //QString start_time_text = time.toString("hh:mm:ss:zzz");
    //showTime(startTime);
    timer = new QTimer(this);//showTime();
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    ui->lcdNumber->display("00:00:00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()  //QTime* st   ?
{
    //QTimer* timer = new QTimer(this);//showTime();
    //connect(timer, SIGNAL(timeout()), this, SLOT(on_startStop_clicked()));
    //timer->start();

/*    int hundredths = ElapsedTime.elapsed() / 10;
    int seconds = hundredths / 100;
    int minutes = seconds / 60;
    hundredths = hundredths % 100;
    seconds = seconds % 60;
    minutes = minutes % 60;
    QString displayTime = QString("%1:%2:%3").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')).arg(hundredths, 2, 10, QLatin1Char('0')); //minutes + ":" + seconds + ":" + hundredths;
    //QString displayTime = QString::number(minutes) + ":" + QString::number(seconds) + ":" + QString::number(hundredths);
    //ui->label->setText(displayTime);
    ui->lcdNumber->display(displayTime);
*/
    int milliseconds = ElapsedTime.elapsed();
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    int hours = minutes / 60;
    milliseconds %= 1000;
    seconds %= 60;
    minutes %= 60;
    //QString displayTime = QString("%1:%2:%3").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')).arg(hundredths, 2, 10, QLatin1Char('0')); //minutes + ":" + seconds + ":" + hundredths;
    //QString displayTime = QString::number(minutes) + ":" + QString::number(seconds) + ":" + QString::number(hundredths);



    QTime elapsed_time(hours, minutes, seconds, milliseconds);
    QString time_text = elapsed_time.toString("mm:ss:zzz");
    ui->lcdNumber->display(time_text.remove(8,1));
}

void MainWindow::on_startStop_clicked()
{
    if(ui->startStop->text() == "Start")
    {

        timer->start(10);
        ElapsedTime.start();
        //QTime* elapsedTime = new QTime(this);
        //elapsedTime->start();
        showTime(); //elapsedTime
        //QThread::msleep(2222);
        //ui->lcdNumber->display(timer->interval());
        //ui->label->setText(QString::number(timer->interval()));
        //timer->stop();
        ui->startStop->setText("Stop");
    }else
    {
        timer->stop();
        ui->startStop->setText("Start");
    }
}
