#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QTextBrowser>
#include <QTextEdit>

class QTextBrowser;
class QTextEdit;
class QEvent;

class ChatWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *e);
    void submitChatText();

private:
    QTextBrowser* conversationView;
    QTextEdit* chatEdit;

signals:

public slots:
};

#endif // CHATWINDOW_H
