#include "TelephoneBookMainView.h"
#include "ui_telephonebookmainview.h"

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
        ui->listEntries->addItem(name);
    }
}
