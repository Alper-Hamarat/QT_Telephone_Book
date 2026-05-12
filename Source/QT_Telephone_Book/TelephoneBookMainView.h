#ifndef TELEPHONEBOOKMAINVIEW_H
#define TELEPHONEBOOKMAINVIEW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "Entry.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class TelephoneBookMainView;
}
QT_END_NAMESPACE

/*
 * Main application window of the
 * telephone book application.
 *
 * Responsible for displaying entries
 * and forwarding user interactions
 * through Qt signals.
 */
class TelephoneBookMainView : public QMainWindow
{
    Q_OBJECT

public:

    /*
     * Creates the main window UI.
     */
    TelephoneBookMainView(QWidget *parent = nullptr);

    /*
     * Cleans up allocated UI resources.
     */
    ~TelephoneBookMainView();

    /*
     * Updates the entry list displayed
     * in the UI.
     */
    void setEntries(std::vector<Entry>& entries);

    /*
     * Displays the selected entry
     * information in the UI.
     */
    void showEntry(Entry &entry);

signals:

    /*
     * Emitted when an entry
     * is selected from the list.
     */
    void entrySelected(string name);

    /*
     * Emitted when the user requests
     * deletion of an entry.
     */
    void deleteEntryRequested(string name);

    /*
     * Emitted when the user requests
     * creation of a new entry.
     */
    void addEntryRequested(string name,
                           string phone,
                           string address);

    /*
     * Emitted when the user requests
     * editing of an existing entry.
     */
    void editEntryRequested(string entryName,
                            string newName,
                            string newPhone,
                            string newAddress);

private slots:

    /*
     * Triggered when a list item
     * is clicked by the user.
     */
    void on_listEntries_itemClicked(QListWidgetItem *item);

    /*
     * Triggered when the delete button
     * is pressed.
     */
    void on_btnDelete_clicked();

    /*
     * Triggered when the add button
     * is pressed.
     */
    void on_btnAdd_clicked();

    /*
     * Triggered when the edit button
     * is pressed.
     */
    void on_btnEdit_clicked();

private:

    // Pointer to the generated Qt UI
    Ui::TelephoneBookMainView *ui;
};

#endif // TELEPHONEBOOKMAINVIEW_H
