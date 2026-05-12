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
    QObject::connect(view, &TelephoneBookMainView::entrySelected,
                     view,
                     [this] (string name) {selectEntry(name); });
    QObject::connect(view, &TelephoneBookMainView::deleteEntryRequested,
                     view,
                     [this](string name) { deleteEntry(name); });
    QObject::connect(view, &TelephoneBookMainView::addEntryRequested,
                     view,
                     [this](string name, string phone, string address)
                     { addEntry(name, phone, address); });
}

void TelephoneBookController::deleteEntry(std::string name)
{
    this->model->removeEntry(name);
    std::vector<Entry> entries = this->model->getEntries();
    this->view->setEntries(entries);
}

void TelephoneBookController::addEntry(string name, string phone, string address)
{
    Entry newEntry(name, phone, address);
    this->model->addEntry(newEntry);
    std::vector<Entry> entries = this->model->getEntries();
    this->view->setEntries(entries);
}

void TelephoneBookController::selectEntry(std::string name)
{
    Entry* entry = model->getEntry(name);

    if (entry == nullptr)
        return;

    view->showEntry(*entry);
}

void TelephoneBookController::editEntry(string entryName, string newName, string newPhone, string newAddress)
{
    Entry newEntry(newName, newPhone, newAddress);
    this->model->editEntry(entryName, newEntry);
}

void TelephoneBookController::run()
{
    //Show the view
    this->view->show();
    Entry * empty = new Entry();
    this->model->addEntry(*empty);
    vector<Entry> entries = this->model->getEntries();

    this->view->setEntries(entries);
}
