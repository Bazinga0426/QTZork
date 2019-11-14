#include "lantern.h"

lantern::lantern(string description, int v): Item(description, v)
{
    setvalue(v);
    setdescription(description);
}

void lantern::act(Character& User){
    User.setlantern();
    setmessage("You found a lantern! Bringing light into the darkness!");
}
