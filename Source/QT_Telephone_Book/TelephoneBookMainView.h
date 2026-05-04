#ifndef TELEPHONEBOOKMAINVIEW_H
#define TELEPHONEBOOKMAINVIEW_H

#include <QMainWindow>

#include "Entry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TelephoneBookMainView; }
QT_END_NAMESPACE

class TelephoneBookMainView : public QMainWindow
{
    Q_OBJECT

public:
    TelephoneBookMainView(QWidget *parent = nullptr);
    ~TelephoneBookMainView();
    void setEntries(std::vector<Entry *>& entries);

private:
    Ui::TelephoneBookMainView *ui;
};
#endif // TELEPHONEBOOKMAINVIEW_H
