#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "item.h"
#include "Room.h"

class enemy: public Character{


public:
    enemy(string description, int attackpoints, int healthpoints);
    ~enemy();
    void act(Character& User);
    void addmessage();
};

#endif // ENEMY_H
