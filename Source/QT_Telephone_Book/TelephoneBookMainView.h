#ifndef TELEPHONEBOOKMAINVIEW_H
#define TELEPHONEBOOKMAINVIEW_H

#include <QMainWindow>
#include <QListWidgetItem>
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

private slots:
    void on_listEntries_itemClicked(QListWidgetItem *item);

private:
    Ui::TelephoneBookMainView *ui;
};
#endif // TELEPHONEBOOKMAINVIEW_H
