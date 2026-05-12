#include "Entry.h"

/*
 * Creates a new entry with custom values.
 */
Entry::Entry(string name, string telNr, string address)
    : name(name), telNr(telNr), address(address)
{
}

/*
 * Creates a default entry with predefined values.
 */
Entry::Entry()
    : Entry("Max Mustermann", "012345678", "Musterstadt")
{
}

/*
 * Returns the name of the entry.
 */
string Entry::getName()
{
    return this->name;
}

/*
 * Sets a new name if the value is not empty.
 */
void Entry::setName(string newName)
{
    if(newName != "")
    {
        this->name = newName;
    }
    else
    {
        cout << "Name: " << newName
             << " has not been assigned to entry" << endl;
    }
}

/*
 * Returns the telephone number.
 */
string Entry::getTelNr()
{
    return this->telNr;
}

/*
 * Sets a new telephone number if the value is not empty.
 */
void Entry::setTelNr(string newTelNr)
{
    if(newTelNr != "")
    {
        this->telNr = newTelNr;
    }
    else
    {
        cout << "TelNr: " << newTelNr
             << " has not been assigned to entry" << endl;
    }
}

/*
 * Returns the address.
 */
string Entry::getAddress()
{
    return this->address;
}

/*
 * Sets a new address if the value is not empty.
 */
void Entry::setAddress(string address)
{
    if(address != "")
    {
        this->address = address;
    }
    else
    {
        cout << "Address: " << address
             << " has not been assigned to entry" << endl;
    }
}

/*
 * Prints all entry information to the console.
 */
void Entry::printEntry()
{
    cout << "-------------------------------" << endl;
    cout << "Entry information: " << endl;
    cout << "Name: " << this->name << endl;
    cout << "TelNr: " << this->telNr << endl;
    cout << "Address: " << this->address << endl;
    cout << "-------------------------------" << endl;
}
