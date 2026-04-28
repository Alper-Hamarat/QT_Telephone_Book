#include "TelephoneBookController.h"

#include "Company.h"
#include "Office.h"
#include "Person.h"

TelephoneBookController::TelephoneBookController(TelephoneBookView * view , TelephoneBookModel * model)
{
    this->view = view;
    this->model = model;
}

string TelephoneBookController::getUserInput(string textToDisplay)
{
    cout << textToDisplay << endl;
    string toReturn = "";
    cin >> toReturn;
    return toReturn;
}

char TelephoneBookController::getMenuInput(string textToDisplay)
{
    cout << textToDisplay << endl;
    char toReturn = ' ';
    cin >> toReturn;
    return toReturn;
}

void TelephoneBookController::run()
{
    char menuInput = '0';
    while(menuInput != '9')
    {
        //Show menu from view
        this->view->showMenu();
        //Get Input from user which actions to perform
        menuInput = this->getMenuInput("Which action would you like to perform?");
        //Switch based on user input

        switch (menuInput)
        {
        case '1':
        {
            vector<Entry *> entries = this->model->getEntries();
            if(entries.empty())
            {
                cout << "The telephoneBook is currently empty " << endl;
            }
            else
            {
                /* Print the Telephone Book */
                for(auto i = entries.begin(); i < entries.end(); i++)
                {
                    (*i)->printEntry();
                }
            }
            break;
        }
        case '2':
        {
            string nameToGet = this->getUserInput("Please enter the name of the user");
            Entry * entry = this->model->getEntry(nameToGet);
            if(entry == NULL)
            {
                cout << "No Entry found for: " << nameToGet << endl;
            }
            else
            {
                entry->printEntry();
            }
            break;
        }
        case '3':
        {
            char entryType = this->getMenuInput("Please enter:\n (C) for Company, (O) for Office, (P) for Person");

            Entry * newEntry = NULL;

            string nameToAdd = "";
            string telNrToAdd = "";
            string addressToAdd = "";
            string designation = "";
            string contactPerson = "";
            string firstName = "";
            string lastName = "";
            switch (entryType)
            {
            case 'C':
                nameToAdd = this->getUserInput("Please enter the Company Name");
                telNrToAdd = this->getUserInput("Please enter the Company Phone Nr");
                addressToAdd = this->getUserInput("Please enter the Company Address");
                contactPerson = this->getUserInput("Please enther the Company Contact Person ");
                newEntry = new Company(nameToAdd, telNrToAdd, addressToAdd, contactPerson);
                break;
            case 'O':
                nameToAdd = this->getUserInput("Please enter the Office Name");
                telNrToAdd = this->getUserInput("Please enter the Office Phone Nr");
                addressToAdd = this->getUserInput("Please enter the Office Address");
                designation = this->getUserInput("Please enter the Office designation");
                newEntry = new Office(nameToAdd, telNrToAdd, addressToAdd, designation);
                break;
            case 'P':
                firstName = this->getUserInput("Please enter the Persons First Name");
                lastName = this->getUserInput("Please enter the Persons Last Name");
                telNrToAdd = this->getUserInput("Please enter the Office Phone Nr");
                addressToAdd = this->getUserInput("Please enter the Office Address");
                newEntry = new Person(firstName, lastName, telNrToAdd, addressToAdd);
                break;
            default:
                break;
            }

            this->model->addEntry(*newEntry);
            break;
        }
        case '4':
        {
            string nameToRemove = this->getUserInput("Please enter the name of the user to remove");
            this->model->removeEntry(nameToRemove);
            break;
        }
        default:
            break;
        }
    }
}