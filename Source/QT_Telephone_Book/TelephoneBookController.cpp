#include "TelephoneBookController.h"

/*
 * Creates the controller and assigns
 * the view and model references.
 */
TelephoneBookController::TelephoneBookController(
    TelephoneBookMainView * view,
    TelephoneBookModel * model)
{
    this->view = view;
    this->model = model;
}

/*
 * Initializes all signal-slot connections
 * between the view and controller logic.
 */
void TelephoneBookController::init()
{
    QObject::connect(view,
                     &TelephoneBookMainView::entrySelected,
                     view,
                     [this](string name)
                     {
                         selectEntry(name);
                     });

    QObject::connect(view,
                     &TelephoneBookMainView::deleteEntryRequested,
                     view,
                     [this](string name)
                     {
                         deleteEntry(name);
                     });

    QObject::connect(view,
                     &TelephoneBookMainView::addEntryRequested,
                     view,
                     [this](string name,
                            string phone,
                            string address)
                     {
                         addEntry(name, phone, address);
                     });

    QObject::connect(view,
                     &TelephoneBookMainView::editEntryRequested,
                     view,
                     [this](string entryName,
                            string name,
                            string phone,
                            string address)
                     {
                         editEntry(entryName,
                                   name,
                                   phone,
                                   address);
                     });
}

/*
 * Removes an entry from the model
 * and refreshes the view.
 */
void TelephoneBookController::deleteEntry(std::string name)
{
    this->model->removeEntry(name);
    this->getEntries();
}

/*
 * Creates and adds a new entry
 * to the model.
 */
void TelephoneBookController::addEntry(
    string name,
    string phone,
    string address)
{
    Entry newEntry(name, phone, address);

    this->model->addEntry(newEntry);

    this->getEntries();
}

/*
 * Retrieves a selected entry from the model
 * and displays it in the view.
 */
void TelephoneBookController::selectEntry(std::string name)
{
    Entry* entry = model->getEntry(name);

    if (entry == nullptr)
        return;

    view->showEntry(*entry);
}

/*
 * Updates an existing entry
 * with new values.
 */
void TelephoneBookController::editEntry(
    string entryName,
    string newName,
    string newPhone,
    string newAddress)
{
    Entry newEntry(newName,
                   newPhone,
                   newAddress);

    this->model->editEntry(entryName, newEntry);

    this->getEntries();
}

/*
 * Loads all entries from the model
 * and updates the view list.
 */
void TelephoneBookController::getEntries()
{
    std::vector<Entry> entries =
        this->model->getEntries();

    this->view->setEntries(entries);
}

/*
 * Starts the application,
 * shows the UI and loads initial data.
 */
void TelephoneBookController::run()
{
    // Show the main window
    this->view->show();

    // Create a default entry
    Entry * empty = new Entry();

    // Add the default entry to the model
    this->model->addEntry(*empty);

    // Load all entries into the view
    this->getEntries();
}
