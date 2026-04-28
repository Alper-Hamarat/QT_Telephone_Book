#include "telephonebookmainview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelephoneBookMainView w;
    w.show();
    return a.exec();
}
