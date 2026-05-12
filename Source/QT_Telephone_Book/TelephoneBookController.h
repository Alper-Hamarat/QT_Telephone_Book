#ifndef TELEPHONEBOOKCONTROLLER_H
#define TELEPHONEBOOKCONTROLLER_H

#include <iostream>

#include "TelephoneBookModel.h"
#include "TelephoneBookMainView.h"


using namespace std;

class TelephoneBookController
{

private:
    TelephoneBookMainView * view;
    TelephoneBookModel * model;
public:
    TelephoneBookController(TelephoneBookMainView * view , TelephoneBookModel * model);
    void init();
    void selectEntry(std::string name);
    void deleteEntry(std::string name);
    void addEntry(string name, string phone, string adress);
    void editEntry(string entryName, string newName, string newPhone, string newAddress);
    void run();
};

#endif /* TELEPHONEBOOKCONTROLLER_H */
