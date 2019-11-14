#ifndef HEALER_H
#define HEALER_H
#include "Character.h"
#include "Room.h"

class healer: public Character
{
public:
    healer(string description, int attackpoints, int healthpoints);
    void act(Character& User);
};

#endif // HEALER_H
