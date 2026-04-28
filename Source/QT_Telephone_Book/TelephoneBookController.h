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
    void run();
};

#endif /* TELEPHONEBOOKCONTROLLER_H */
