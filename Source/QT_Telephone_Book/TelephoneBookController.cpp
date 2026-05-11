#include "TelephoneBookController.h"

#include "Company.h"
#include "Office.h"
#include "Person.h"

TelephoneBookController::TelephoneBookController(TelephoneBookMainView * view , TelephoneBookModel * model)
{
    this->view = view;
    this->model = model;
}

void TelephoneBookController::init()
{
    QObject::connect(view, &TelephoneBookMainView::deleteEntryRequested,
                     view,
                     [this](Entry *entry) { deleteEntry(entry); });
}

void TelephoneBookController::deleteEntry(Entry * entry)
{
    this->model->removeEntry(entry->getName());
    std::vector<Entry *> entries = this->model->getEntries();
    this->view->setEntries(entries);
}

void TelephoneBookController::run()
{
    //Show the view
    this->view->show();
    Entry * empty = new Entry();
    this->model->addEntry(*empty);
    vector<Entry *> entries = this->model->getEntries();

    this->view->setEntries(entries);
}
