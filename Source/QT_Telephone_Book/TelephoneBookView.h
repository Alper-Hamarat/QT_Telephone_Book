#ifndef TELEPHONEBOOKVIEW_H
#define TELEPHONEBOOKVIEW_H

#include <string>
#include "ViewListener.h"

using namespace std;

class TelephoneBookView
{

private:
    ViewListener * listener;

public:
    void showMenu(); 
    void showTelephoneBook(); 
    void setListener(ViewListener * listener);
};

#endif /* TELEPHONEBOOKVIEW_H */