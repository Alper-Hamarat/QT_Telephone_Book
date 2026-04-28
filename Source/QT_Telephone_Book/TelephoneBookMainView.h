#ifndef TELEPHONEBOOKMAINVIEW_H
#define TELEPHONEBOOKMAINVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TelephoneBookMainView; }
QT_END_NAMESPACE

class TelephoneBookMainView : public QMainWindow
{
    Q_OBJECT

public:
    TelephoneBookMainView(QWidget *parent = nullptr);
    ~TelephoneBookMainView();

private:
    Ui::TelephoneBookMainView *ui;
};
#endif // TELEPHONEBOOKMAINVIEW_H
