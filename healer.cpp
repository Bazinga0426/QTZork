#include "healer.h"

healer::healer(string description, int attackpoints, int healthpoints): Character ( description, attackpoints, healthpoints)
{

}

void healer::act(Character& User){
    User.sethealth(200);
    setmessage("You've seem to met someone nice here. Your wounds are healed.");
}
