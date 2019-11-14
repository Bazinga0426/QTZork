#include "medaillon.h"

medaillon::medaillon(string description, int v): Item(description, v)
{
    setdescription(description);
}

void medaillon::act(Character& User){
   User.setteleport();
   setmessage("You found the Teleport-Medaillon! Now you can teleport.");
}
