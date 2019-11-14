#include "shield.h"

shield::shield(string description, int v): Item(description, v)
{
    setvalue(v);
    setdescription(description);
}

void shield::act(Character& User){
    User.setshield();
    setmessage("You found a "+getDescription()+"! Stick and Stones won't break this fella!");
}
