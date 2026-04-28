#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>

using namespace std;

class Entry
{
protected:
    string name;
    string telNr;
    string address;
public:
    Entry(string name, string telNr, string address);
    Entry();
    
    virtual string getName();
    void setName(string newName);

    string getTelNr();
    void setTelNr(string newTelNr);

    string getAddress();
    void setAddress(string newAddress);

    virtual void printEntry();
};

#endif /* ENTRY_H */