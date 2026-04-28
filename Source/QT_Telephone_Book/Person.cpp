#include "Person.h"

Person::Person(string firstName, string lastName, string newTelNr, string newAddress) : Entry(firstName + lastName, newTelNr, newAddress)
{
    this->setFirstName(firstName);
    this->setLastName(lastName);
}


Person::Person() : Entry("Max Mustermann", "0123456", "012345 Musterstadt")
{
    this->setFirstName("Max");
    this->setLastName("Mustermann");
}

//Is used to override the standard getName function for the entry class to help the getEntry funciton
string Person::getName()
{
    return this->getFirstName() + "_" + this->getLastName();
}

string Person::getFirstName()
{
    return this->firstName;
}


void Person::setFirstName(string newName)
{
    if(newName != "")
    {
        this->firstName = newName;
    }
    else
    {
        cout <<  "First Name: " << newName <<  " has not been assigned to Person" << endl;
    }
}

string Person::getLastName()
{
    return this->lastName;
}

void Person::setLastName(string newName)
{
    if(newName != "")
    {
        this->lastName = newName;
    }
    else
    {
        cout <<  "Last Name: " << newName <<  " has not been assigned to Person" << endl;
    }
}

void Person::printEntry()
{
    cout << "-------------------------------" << endl;
    cout << "Person information: " << endl;
    cout << "First Name: " << this->firstName << endl;
    cout << "Last Name: " << this->lastName << endl;
    cout << "TelNr: " << this->telNr << endl;
    cout << "Address: " << this->address << endl;
    cout << "-------------------------------" << endl;
}