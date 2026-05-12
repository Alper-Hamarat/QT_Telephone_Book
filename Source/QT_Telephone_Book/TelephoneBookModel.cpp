#include "TelephoneBookModel.h"

#include <optional>

/*
 * Returns all stored telephone book entries.
 */
vector<Entry> TelephoneBookModel::getEntries()
{
    return listEntries;
}

/*
 * Searches for an entry by name.
 *
 * Returns a pointer to the matching entry
 * or nullptr if no entry was found.
 */
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

/*
 * Adds a new entry to the model.
 *
 * Returns false if an entry with
 * the same name already exists.
 */
bool TelephoneBookModel::addEntry(Entry& newEntry)
{
    // Prevent duplicate entries
    if (getEntry(newEntry.getName()) != nullptr)
    {
        return false;
    }

    // Store the new entry
    listEntries.push_back(newEntry);

    return true;
}

/*
 * Removes an entry identified by name.
 *
 * Returns true if the entry was removed.
 */
bool TelephoneBookModel::removeEntry(std::string name)
{
    for (auto it = listEntries.begin();
         it != listEntries.end();
         ++it)
    {
        if (it->getName() == name)
        {
            listEntries.erase(it);

            return true;
        }
    }

    return false;
}

/*
 * Updates an existing entry
 * with new data.
 *
 * Returns false if the entry
 * does not exist.
 */
bool TelephoneBookModel::editEntry(std::string name,
                                   Entry& newEntry)
{
    // Search for the existing entry
    Entry* oldEntry = getEntry(name);

    if (oldEntry == nullptr)
    {
        return false;
    }

    // Replace old entry data
    *oldEntry = newEntry;

    return true;
}
