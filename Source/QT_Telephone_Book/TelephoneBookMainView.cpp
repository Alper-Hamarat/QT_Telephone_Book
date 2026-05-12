#include "TelephoneBookMainView.h"
#include "ui_TelephoneBookMainView.h"

// Stores the currently selected entry name
string selectedName;

/*
 * Creates and initializes the main UI window.
 */
TelephoneBookMainView::TelephoneBookMainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelephoneBookMainView)
{
    ui->setupUi(this);
}

/*
 * Cleans up allocated UI resources.
 */
TelephoneBookMainView::~TelephoneBookMainView()
{
    delete ui;
}

/*
 * Updates the list widget with all entries
 * from the model.
 */
void TelephoneBookMainView::setEntries(std::vector<Entry>& entries)
{
    // Remove all current list entries
    ui->listEntries->clear();

    // Add all entries to the list widget
    for (Entry& entry : entries)
    {
        QString name =
            QString::fromStdString(entry.getName());

        QListWidgetItem* item =
            new QListWidgetItem(name);

        // Store the entry name inside the item
        item->setData(Qt::UserRole, name);

        ui->listEntries->addItem(item);
    }
}

/*
 * Displays entry data inside the input fields.
 */
void TelephoneBookMainView::showEntry(Entry& entry)
{
    ui->lineNameAdd->setText(
        QString::fromStdString(entry.getName()));

    ui->linePhoneAdd->setText(
        QString::fromStdString(entry.getTelNr()));

    ui->lineAddressAdd->setText(
        QString::fromStdString(entry.getAddress()));
}

/*
 * Triggered when the user selects
 * an entry from the list.
 */
void TelephoneBookMainView::on_listEntries_itemClicked(
    QListWidgetItem *item)
{
    // Read the stored entry name
    selectedName =
        item->data(Qt::UserRole)
            .toString()
            .toStdString();

    // Notify the controller
    emit entrySelected(selectedName);
}

/*
 * Triggered when the delete button is pressed.
 */
void TelephoneBookMainView::on_btnDelete_clicked()
{
    // Clear input fields
    ui->lineNameAdd->setText("");
    ui->linePhoneAdd->setText("");
    ui->lineAddressAdd->setText("");

    // Notify the controller
    emit deleteEntryRequested(selectedName);
}

/*
 * Triggered when the add button is pressed.
 */
void TelephoneBookMainView::on_btnAdd_clicked()
{
    // Read user input from UI fields
    string name =
        ui->lineNameAdd->text().toStdString();

    string phone =
        ui->linePhoneAdd->text().toStdString();

    string address =
        ui->lineAddressAdd->text().toStdString();

    // Notify the controller
    emit addEntryRequested(name,
                           phone,
                           address);

    // Clear input fields
    ui->lineNameAdd->setText("");
    ui->linePhoneAdd->setText("");
    ui->lineAddressAdd->setText("");
}

/*
 * Triggered when the edit button is pressed.
 */
void TelephoneBookMainView::on_btnEdit_clicked()
{
    // Read updated user input
    string name =
        ui->lineNameAdd->text().toStdString();

    string phone =
        ui->linePhoneAdd->text().toStdString();

    string address =
        ui->lineAddressAdd->text().toStdString();

    // Notify the controller
    emit editEntryRequested(selectedName,
                            name,
                            phone,
                            address);

    // Clear input fields
    ui->lineNameAdd->setText("");
    ui->linePhoneAdd->setText("");
    ui->lineAddressAdd->setText("");
}
