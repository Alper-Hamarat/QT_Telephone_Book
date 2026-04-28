#ifndef VIEWLISTENER_H
#define VIEWLISTENER_H

#include <string>

using namespace std;

class ViewListener
{
    virtual string getUserInput(string textToDisplay) = 0; 
    virtual char getMenuInput(string textToDisplay) = 0; 
};

#endif /* VIEWLISTENER_H */