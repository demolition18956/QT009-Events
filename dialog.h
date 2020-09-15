#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    bool event(QEvent* someEvent);  // Generic
                                    // Event Handler

private:
    Ui::Dialog *ui;
    int updateTimer;
    bool paused;

private slots:
    void initiateTimer();
    void pauseTimer();
    void clearTimer();
};

#endif // DIALOG_H
