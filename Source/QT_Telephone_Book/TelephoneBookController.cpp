#include "TelephoneBookController.h"

#include "Company.h"
#include "Office.h"
#include "Person.h"

TelephoneBookController::TelephoneBookController(TelephoneBookMainView * view , TelephoneBookModel * model)
{
    this->view = view;
    this->model = model;
}

void TelephoneBookController::run()
{
    this->view->show();
}
