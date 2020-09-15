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
    updateTimer = QObject::startTimer(1000); // Set off Event every
                                             // 1000 msec (returns
                                             // timer id)
    paused = true;

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(initiateTimer()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearTimer()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));

    QTimerEvent* event = new QTimerEvent(updateTimer);  // returns Timer Event associated
                                                        // id

    QCoreApplication::postEvent(this, event);   // Manually add to event queue
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::timerEvent(QTimerEvent *someEvent)
{
    if (!someEvent) return; // make sure event exists
    if (someEvent->timerId() == updateTimer) // if the custom timer created
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
    else {
        QObject::timerEvent(someEvent);
    }
}

void Dialog::initiateTimer()
{
    qDebug() << "Initiating Timer";
    paused = false;
}

void Dialog::pauseTimer()
{
    qDebug() << "Pausing Timer";
    paused = true;
}

void Dialog::clearTimer()
{
    qDebug() << "Clearing Timer";
    ui->timeLabel->setText("0");
    paused = true;
}
