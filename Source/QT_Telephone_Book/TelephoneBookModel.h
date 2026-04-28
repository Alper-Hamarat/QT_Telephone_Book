#ifndef TELEPHONEBOOKMODEL_H
#define TELEPHONEBOOKMODEL_H

#include <vector>
#include <optional>

#include "Entry.h"

class TelephoneBookModel
{
private:
    vector<Entry *> listEntries;

public:

    vector<Entry *> getEntries();
    Entry * getEntry(string name);
    bool addEntry(Entry & newEntry);
    bool removeEntry(string name);
    bool editEntry(string name, Entry * newEntry);
};

#endif /* TELEPHONEBOOKMODEL_H */