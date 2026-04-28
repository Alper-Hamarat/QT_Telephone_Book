#include "telephonebookmainview.h"
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

