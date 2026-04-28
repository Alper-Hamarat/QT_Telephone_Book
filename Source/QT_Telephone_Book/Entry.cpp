#include "Entry.h"

Entry::Entry(string name, string telNr, string address) : name(name), telNr(telNr), address(address){}

Entry::Entry() : Entry("Max","Mustermann","012345678" ){};

string Entry::getName()
{
    return this->name;
}

void Entry::setName(string newName)
{
    if(newName != "")
    {
        this->name = newName;
    }
    else
    {
        cout <<  "Name: " << newName <<  " has not been assigned to entry" << endl;
    }
}

string Entry::getTelNr()
{
    return this->telNr;
}

void Entry::setTelNr(string newTelNr)
{
    if(newTelNr != "")
    {
        this->telNr = newTelNr;
    }
    else
    {
        cout <<  "TelNr: " << newTelNr <<  " has not been assigned to entry" << endl;
    }
}

string Entry::getAddress()
{
    return this->address;
}

void Entry::setAddress(string address)
{
    if(address != "")
    {
        this->address = address;
    }
    else
    {
        cout <<  "Address: " << address <<  " has not been assigned to entry" << endl;
    }
}

void Entry::printEntry()
{
    cout << "-------------------------------" << endl;
    cout << "Entry information: " << endl;
    cout << "Name: " << this->name << endl;
    cout << "TelNr: " << this->telNr << endl;
    cout << "Address: " << this->address << endl;
    cout << "-------------------------------" << endl;
}