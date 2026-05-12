#ifndef TELEPHONEBOOKMODEL_H
#define TELEPHONEBOOKMODEL_H

#include <vector>
#include <optional>

#include "Entry.h"

/*
 * Stores and manages all telephone
 * book entries.
 *
 * Provides CRUD operations for
 * accessing and modifying entries.
 */
class TelephoneBookModel
{
private:

    // Internal container holding all entries
    std::vector<Entry> listEntries;

public:

    /*
     * Returns all stored entries.
     */
    std::vector<Entry> getEntries();

    /*
     * Returns a pointer to an entry
     * identified by its name.
     *
     * Returns nullptr if no entry exists.
     */
    Entry* getEntry(std::string name);

    /*
     * Adds a new entry to the model.
     *
     * Returns true on success.
     */
    bool addEntry(Entry& newEntry);

    /*
     * Removes an entry identified
     * by its name.
     *
     * Returns true on success.
     */
    bool removeEntry(std::string name);

    /*
     * Updates an existing entry
     * with new values.
     *
     * Returns true on success.
     */
    bool editEntry(std::string name,
                   Entry& newEntry);
};

#endif /* TELEPHONEBOOKMODEL_H */
