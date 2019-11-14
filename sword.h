#ifndef SWORD_H
#define SWORD_H
#include "item.h"

class sword: public Item
{
public:
    sword(string description, int value);
    void act(Character& User);
};

#endif // SWORD_H
