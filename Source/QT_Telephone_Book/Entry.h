#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>

using namespace std;

/*
 * Represents a single telephone book entry.
 * Stores basic contact information such as
 * name, telephone number and address.
 */
class Entry
{
protected:
    // Name of the entry/person
    string name;

    // Telephone number of the entry
    string telNr;

    // Address of the entry
    string address;

public:

    /*
     * Creates an entry with initialized values.
     */
    Entry(string name, string telNr, string address);

    /*
     * Default constructor.
     */
    Entry();

    /*
     * Returns the name of the entry.
     */
    virtual string getName();

    /*
     * Sets a new name for the entry.
     */
    void setName(string newName);

    /*
     * Returns the telephone number.
     */
    string getTelNr();

    /*
     * Sets a new telephone number.
     */
    void setTelNr(string newTelNr);

    /*
     * Returns the address.
     */
    string getAddress();

    /*
     * Sets a new address.
     */
    void setAddress(string newAddress);

    /*
     * Prints the entry information.
     */
    virtual void printEntry();
};

#endif /* ENTRY_H */
