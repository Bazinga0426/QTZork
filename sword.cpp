#include "sword.h"

sword::sword(string description, int v): Item(description, v)
{
    setvalue(v);
    setdescription(description);
}

void sword::act(Character& User){
    User.setattack(this->getvalue());
    User.setweapon();
    setmessage("You found a sword! Evil-doers beware, for you are now stronger!");
}
