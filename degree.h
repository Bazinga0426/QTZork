#ifndef DEGREE_H
#define DEGREE_H
#include "item.h"

class degree : public Item
{
public:
    degree(string description, int value);
    void act(Character& User);
};

#endif // DEGREE_H
