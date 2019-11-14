#include "hero.h"

hero::hero(string description, int attackpoints, int healthpoints): Character ( description, attackpoints, healthpoints)
{
    this->setinithealth(100);
    this->keys=0;

}

hero::~hero(){}
void hero::act(Character& User){

}


