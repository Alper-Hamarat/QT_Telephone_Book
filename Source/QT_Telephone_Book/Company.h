#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include "Entry.h"

using namespace std;

class Company : public Entry
{
protected:
    string contactPerson;
public:
    Company(string name, string telNr, string address, string contactPerson);
    Company();
    string getContactPerson();
    void setContactPerson(string newContactPerson);

    void printEntry() override;
};

#endif /* COMPANY_H */