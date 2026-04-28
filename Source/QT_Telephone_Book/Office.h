#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include "Entry.h"

using namespace std;

class Office : public Entry
{
protected:
    string designation;
public:
    Office(string name, string telNr, string address, string designation);
    Office();
    string getDesignation();
    void setDesignation(string newDesignation);

    void printEntry() override;
};

#endif /* OFFICE_H */