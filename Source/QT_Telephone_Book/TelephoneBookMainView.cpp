#include "TelephoneBookMainView.h"
#include "ui_TelephoneBookMainView.h"

//Set when user clicks on Entry
Entry * selectedEntry;

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

void TelephoneBookMainView::setEntries(std::vector<Entry *>& entries)
{
    ui->listEntries->clear();

    for (auto& entry : entries)
    {
        QString name = QString::fromStdString(entry->getName());

        QListWidgetItem* item = new QListWidgetItem(name);

        item->setData(Qt::UserRole,
                      QVariant::fromValue(reinterpret_cast<quintptr>(entry)));

        ui->listEntries->addItem(item);
    }
}

void TelephoneBookMainView::on_listEntries_itemClicked(QListWidgetItem *item)
{
    quintptr ptrValue = item->data(Qt::UserRole).value<quintptr>();

    selectedEntry = reinterpret_cast<Entry*>(ptrValue);

    ui->lblName->setText(QString::fromStdString(selectedEntry->getName()));
    ui->lblTelNr->setText(QString::fromStdString(selectedEntry->getTelNr()));
    ui->lblAddress->setText(QString::fromStdString(selectedEntry->getAddress()));
}


void TelephoneBookMainView::on_btnDelete_clicked()
{
    emit deleteEntryRequested(selectedEntry);
}

