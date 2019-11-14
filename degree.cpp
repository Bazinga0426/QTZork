#include "degree.h"

degree::degree(string description, int v): Item(description, v)
{
    setvalue(v);
    setdescription(description);
}

void degree::act(Character& User){
    setmessage("You found an Arts-Degree! Unfortunately its useless in any situation!");
}
