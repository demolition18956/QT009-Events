#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->timeLabel->setText("0");
    timer = new QTimer(this);   // allocates timer
    timer->setInterval(1000);   // sets timer interval
                                // timer not started yet
    paused = true;

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(initiateTimer()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearTimer()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));  // uses signal/slot connections
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateDisplay()
{
    if (!paused)
    {
        bool ok;
        int n = ui->timeLabel->text().toInt(&ok) + 1; // make sure value is an integer
                                                      // answer found in "ok"
        if (ok)
        {
            ui->timeLabel->setText(QString::number(n));
            qDebug() << "Updating display";
        }
        else {
            ui->timeLabel->setText("");
            qDebug() << "Dialog::eventTimer(): Unknown error";
        }
    }
    else {
        qDebug() << "Timer paused";
    }
}

void Dialog::initiateTimer()
{
    qDebug() << "Initiating Timer";
    paused = false;
    timer->start();
}

void Dialog::pauseTimer()
{
    qDebug() << "Pausing Timer";
    paused = true;
    timer->stop();
}

void Dialog::clearTimer()
{
    qDebug() << "Clearing Timer";
    ui->timeLabel->setText("0");
    paused = true;
    timer->stop();
}
