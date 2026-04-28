#ifndef PERSON_H
#define PERSON_H

#include "Entry.h"

class Person : public Entry
{
private:
    string firstName;
    string lastName;
public:
    Person(string firstName, string lastName, string newTelNr, string newAddress);
    Person();
    
    string getFirstName();
    void setFirstName(string newName);

    string getLastName();
    void setLastName(string newName);

    string getName() override;

    void printEntry() override;
};

#endif /* PERSON_H */