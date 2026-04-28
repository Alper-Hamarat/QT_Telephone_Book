#include "telephonebookmainview.h"
#include "TelephoneBookController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    TelephoneBookView view;
    TelephoneBookModel model;

    TelephoneBookController controller(&view, &model);
    view.setListener(&controller);

    controller.run();
    QApplication a(argc, argv);
    TelephoneBookMainView w;
    w.show();
    return a.exec();
}
