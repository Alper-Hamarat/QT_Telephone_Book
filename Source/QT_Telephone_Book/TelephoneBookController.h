#ifndef TELEPHONEBOOKCONTROLLER_H
#define TELEPHONEBOOKCONTROLLER_H

#include <iostream>

#include "ViewListener.h"
#include "TelephoneBookModel.h"
#include "TelephoneBookView.h"


using namespace std;

class TelephoneBookController : public ViewListener
{

private:
    TelephoneBookView * view;
    TelephoneBookModel * model;
public:
    string getUserInput(string textToDisplay) override; 
    char getMenuInput(string textToDisplay) override; 
    
    TelephoneBookController(TelephoneBookView * view , TelephoneBookModel * model);
    void run();
};

#endif /* TELEPHONEBOOKCONTROLLER_H */
