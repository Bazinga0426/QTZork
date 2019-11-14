#ifndef SHIELD_H
#define SHIELD_H
#include "item.h"

class shield : public Item
{
public:
    shield(string description, int value);
    void act(Character& User);
};

#endif // SHIELD_H
