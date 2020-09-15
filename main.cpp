#include "dialog.h"
#include "chatwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    ChatWindow c;
    c.show();

    return a.exec();
}
