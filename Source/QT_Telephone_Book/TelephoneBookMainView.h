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
    void setEntries(std::vector<Entry>& entries);
    void showEntry(Entry &entry);
signals:
    void entrySelected(string name);
    void deleteEntryRequested(string name);
    void addEntryRequested(string name,
                           string phone,
                           string address);
    void editEntryRequested(string entryName,
                            string newName,
                            string newPhone,
                            string newAddress);
private slots:
    void on_listEntries_itemClicked(QListWidgetItem *item);

    void on_btnDelete_clicked();

    void on_btnAdd_clicked();

    void on_btnEdit_clicked();

private:
    Ui::TelephoneBookMainView *ui;
};
#endif // TELEPHONEBOOKMAINVIEW_H
