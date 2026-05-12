#include "TelephoneBookMainView.h"
#include "ui_TelephoneBookMainView.h"

//Set when user clicks on Entry
string selectedName;

TelephoneBookMainView::TelephoneBookMainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelephoneBookMainView)
{
    ui->setupUi(this);
}

TelephoneBookMainView::~TelephoneBookMainView()
{
    delete ui;
}

void TelephoneBookMainView::setEntries(std::vector<Entry>& entries)
{
    ui->listEntries->clear();

    for (Entry& entry : entries)
    {
        QString name = QString::fromStdString(entry.getName());

        QListWidgetItem* item = new QListWidgetItem(name);
        item->setData(Qt::UserRole, name);

        ui->listEntries->addItem(item);
    }
}

void TelephoneBookMainView::showEntry(Entry& entry)
{
    ui->lineNameAdd->setText(QString::fromStdString(entry.getName()));
    ui->linePhoneAdd->setText(QString::fromStdString(entry.getTelNr()));
    ui->lineAddressAdd->setText(QString::fromStdString(entry.getAddress()));
}

void TelephoneBookMainView::on_listEntries_itemClicked(QListWidgetItem *item)
{
    selectedName = item->data(Qt::UserRole).toString().toStdString();
    emit entrySelected(selectedName);
}


void TelephoneBookMainView::on_btnDelete_clicked()
{
    ui->lineNameAdd->setText("");
    ui->linePhoneAdd->setText("");
    ui->lineAddressAdd->setText("");
    emit deleteEntryRequested(selectedName);
}


void TelephoneBookMainView::on_btnAdd_clicked()
{
    string name = ui->lineNameAdd->text().toStdString();
    string phone = ui->linePhoneAdd->text().toStdString();
    string address = ui->lineAddressAdd->text().toStdString();

    emit addEntryRequested(name, phone, address);

    ui->lineNameAdd->setText("");
    ui->linePhoneAdd->setText("");
    ui->lineAddressAdd->setText("");
}


