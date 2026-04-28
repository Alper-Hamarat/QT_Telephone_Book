#include <iostream>

#include "TelephoneBookView.h"

using namespace std;

void TelephoneBookView::showMenu()
{
    cout << endl << "-------------------------------" << endl;
    cout << "Welcome to the Telephone Book: " << endl;
    cout << "To navigate press the Key on the Keyboard and press Enter." << endl;
    cout << "1: Show Telephone book" << endl;
    cout << "2: Get an entry from the telephone book" << endl;
    cout << "3: Add an entry in the Telephone book" << endl;
    cout << "4: Remove an entry in the Telephone book" << endl;
    cout << "5: Edit an entry in the Telephone book" << endl;
    cout << "9: Exit the Program" << endl;
    cout << "-------------------------------" << endl;
}

void TelephoneBookView::setListener(ViewListener * listener)
{
    this->listener = listener;
}