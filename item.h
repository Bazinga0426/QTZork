#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include "hero.h"
#include "Character.h"
using namespace std;

class Item {
private:
	string description;
    string message;
    int value;


public:
    Item (string description, int value);
    virtual ~Item ();
    string getDescription();
    int getvalue();
    virtual void act(Character& user);
    void setdescription(string description);
    void setvalue(int value);
    void setmessage(string input);
    string getmessage();

};

#endif /*ITEM_H_*/
