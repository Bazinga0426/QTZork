#ifndef ROOM_H_
#define ROOM_H_
#include <list>
#include <map>
#include <string>
#include "item.h"
#include "Character.h"


using namespace std;

class Room {

private:

	string description;
    string longdescription;
    Room *south;
    Room *west;
    Room *east;
    Room *north;
    Item *Items;
    int row;
    int col;
    Character *Uno;
    bool uno;
    bool dark;
    bool blocked;
    bool iteminroom;
    bool ismasterroom;


public:
    int numberOfItems();
    Room();
	void setExits(Room *north, Room *east, Room *south, Room *west);
    void setDescription(int column, int row);
    string getDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    bool isItemInRoom();
    void setButton();
    bool getButton();
    void reset();
    Room *getsouth();
    void setsouth(Room*);
    Room *getnorth();
    void setnorth(Room *);
    Room *geteast();
    void seteast(Room *);
    Room *getwest();
    void setwest(Room *);
    void setrow(int);
    void setcol(int);
    int getrow();
    int getcol();
    void setcharacteruno(Character *uno);
    void setdarkness();
    bool getdarkness();
    string action(Character& hero);
    void setItem(Item *item);
    bool getitem();
    bool getcharacteruno();
    string collectitem(Character& hero);
    bool getmasterroom();
    void setmasterroom();
    int setlongdescription();
    string getlongdescription();
};

#endif
