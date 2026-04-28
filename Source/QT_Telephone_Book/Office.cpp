#include "Office.h"
#include "Entry.h"

Office::Office(string name, string telNr, string address, string designation) : Entry(name, telNr, address), designation(designation){}

Office::Office() : Office("Some Office", "0123456789", "Some Address", "Some Designation"){}

string Office::getDesignation()
{
    return this->designation;
}

void Office::setDesignation(string newDesignation)
{
    if(newDesignation != "")
    {
        this->designation = newDesignation;
    }
    else
    {
        cout <<  "Designation: " << newDesignation <<  " has not been assigned to Office" << endl;
    }
}

void Office::printEntry()
{
    cout << "-------------------------------" << endl;
    cout << "Office information: " << endl;
    cout << "Name: " << this->name << endl;
    cout << "TelNr: " << this->telNr << endl;
    cout << "Address: " << this->address << endl;
    cout << "Designation: " << this->designation << endl;
    cout << "-------------------------------" << endl;
}