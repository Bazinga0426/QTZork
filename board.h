#ifndef BOARD_H
#define BOARD_H

#include "Room.h"
#include <list>


class Board
{
private:
    Board(int, int);
    int width;
    int height;
    int roomnumber;
    Room * firstRoom;
    Room * recRoom;
    Room * prevRoom;
    Room * rowstart;
    Room * aboveRoom;

    static Board * instance;
    static bool single;
    void buildenviro();

public:
    ~Board();
    void placeinitial();
    static Board * createInstance(int, int); //Singleton-Design-Pattern: Only One Board can exist
    int getheight();
    int getwidth();
    Room * roomlist[25];
    Room *getrecRoom();
    Room *getfirstRoom();
    Room *goeast(Room *);
    Room *gowest(Room *);
    Room *gonorth(Room*);
    Room *gosouth(Room*);
    void actall(int);
    int getroomnumber();
};

#endif // BOARD_H
