#ifndef KEY_H
#define KEY_H
#include "item.h"

class key : public Item
{
public:
    key(string description, int value);
    void act(Character& User);
};

#endif // KEY_H
