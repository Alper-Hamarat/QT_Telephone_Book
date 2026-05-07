#include "TelephoneBookMainView.h"
#include "ui_TelephoneBookMainView.h"

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

    Entry* entry = reinterpret_cast<Entry*>(ptrValue);

    ui->lblName->setText(QString::fromStdString(entry->getName()));
    ui->lblTelNr->setText(QString::fromStdString(entry->getTelNr()));
    ui->lblAddress->setText(QString::fromStdString(entry->getAddress()));
}

