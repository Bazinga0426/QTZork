#ifndef HERO_H
#define HERO_H
#include "Character.h"

class hero: public Character
{

public:
    hero(string description, int attackpoints, int healthpoints);
    ~hero();
    void act(Character& User);

};

#endif // HERO_H
