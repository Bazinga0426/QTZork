#ifndef MEDAILLON_H
#define MEDAILLON_H
#include "item.h"

class medaillon : public Item
{
public:
    medaillon(string description, int value);
    void act(Character& User);
};

#endif // MEDAILLON_H
