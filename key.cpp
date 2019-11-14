#include "key.h"

key::key(string description, int v): Item(description, v)
{
    setvalue(v);
    setdescription(description);
}

void key::act(Character& User){
    User.addkey();
    string tmp="You found the "+getDescription()+"! One step further to your rescue!";
    if(User.getkey()==3)
        tmp=tmp+"\nYou found the three keys! Now can escape this maze!";
    setmessage(tmp);
}
