#include "TelephoneBookModel.h"

#include <optional>

vector<Entry> TelephoneBookModel::getEntries()
{
    return listEntries;
}

Entry* TelephoneBookModel::getEntry(std::string name)
{
    for (Entry& entry : this->listEntries)
    {
        if (entry.getName() == name)
        {
            return &entry;
        }
    }

    return nullptr;
}

bool TelephoneBookModel::addEntry(Entry& newEntry)
{
    if (getEntry(newEntry.getName()) != nullptr)
    {
        return false;
    }

    listEntries.push_back(newEntry);
    return true;
}

bool TelephoneBookModel::removeEntry(std::string name)
{
    for (auto it = listEntries.begin(); it != listEntries.end(); ++it)
    {
        if (it->getName() == name)
        {
            listEntries.erase(it);
            return true;
        }
    }

    return false;
}

bool TelephoneBookModel::editEntry(std::string name,
                                   Entry& newEntry)
{
    Entry* oldEntry = getEntry(name);

    if (oldEntry == nullptr)
    {
        return false;
    }

    *oldEntry = newEntry;
    return true;
}
