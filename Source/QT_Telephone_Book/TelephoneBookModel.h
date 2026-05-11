#ifndef TELEPHONEBOOKMODEL_H
#define TELEPHONEBOOKMODEL_H

#include <vector>
#include <optional>

#include "Entry.h"

class TelephoneBookModel
{
private:
    std::vector<Entry> listEntries;

public:

    std::vector<Entry> getEntries();
    Entry* getEntry(std::string name);
    bool addEntry(Entry& newEntry);
    bool removeEntry(std::string name);
    bool editEntry(std::string name, Entry& newEntry);
};

#endif /* TELEPHONEBOOKMODEL_H */
