#include "item.h"

Item::Item(string inDescription, int v) {
	description = inDescription;
    value=v;
}

Item::~Item(){

}

void Item::act(Character& uno){

}


string Item::getDescription()
{
	return description;
}

int Item::getvalue(){
    return value;
}

void Item::setdescription(string desc){
    this->description=desc;
}

void Item::setvalue(int v){
    this->value=v;
}

void Item::setmessage(string input){
    message=input;
}

string Item::getmessage(){
    return message;
}
