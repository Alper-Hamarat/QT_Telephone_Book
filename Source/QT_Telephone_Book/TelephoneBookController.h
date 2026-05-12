#ifndef TELEPHONEBOOKCONTROLLER_H
#define TELEPHONEBOOKCONTROLLER_H

#include "TelephoneBookMainView.h"
#include "TelephoneBookModel.h"

using namespace std;

/*
 * Controls communication between
 * the view and the model.
 *
 * Handles user interactions and
 * updates the UI with model data.
 */
class TelephoneBookController
{
private:

    // Reference to the main UI view
    TelephoneBookMainView * view;

    // Reference to the telephone book model
    TelephoneBookModel * model;

public:

    /*
     * Creates a controller with
     * assigned view and model.
     */
    TelephoneBookController(TelephoneBookMainView * view,
                            TelephoneBookModel * model);

    /*
     * Initializes signal-slot connections.
     */
    void init();

    /*
     * Selects an entry by name and
     * displays it in the view.
     */
    void selectEntry(std::string name);

    /*
     * Removes an entry from the model.
     */
    void deleteEntry(std::string name);

    /*
     * Adds a new entry to the model.
     */
    void addEntry(string name,
                  string phone,
                  string adress);

    /*
     * Updates an existing entry.
     */
    void editEntry(string entryName,
                   string newName,
                   string newPhone,
                   string newAddress);

    /*
     * Loads all entries from the model
     * and updates the view.
     */
    void getEntries();

    /*
     * Starts the application logic
     * and shows the UI.
     */
    void run();
};

#endif /* TELEPHONEBOOKCONTROLLER_H */
