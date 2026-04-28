#include "TelephoneBookMainView.h"
#include "TelephoneBookController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelephoneBookModel model;
    TelephoneBookMainView view;
    TelephoneBookController controller(&view, &model);
    controller.run();
    return a.exec();
}
