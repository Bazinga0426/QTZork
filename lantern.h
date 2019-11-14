#ifndef LANTERN_H
#define LANTERN_H
#include "item.h"

class lantern : public Item
{
public:
    lantern(string description, int value);
    void act(Character& User);
};

#endif // LANTERN_H
