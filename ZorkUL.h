#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "board.h"
#include "qstring.h"
#include "QTextBrowser"
#include "qprogressbar.h"
#include "key.h"
#include "sword.h"
#include "shield.h"
#include "degree.h"
#include "lantern.h"
#include "enemy.h"
#include "healer.h"
#include "medaillon.h"

using namespace std;

class ZorkUL {
private:
    friend class MainWindow;
	Room *currentRoom;
	void createRooms();
    void init();
    void reset();
	void printHelp();
    void createItems();
    void displayItems();
    void setroomlist(Room* tobeaddedRoom, int place);
    Room* roomlist[25];
    void changeroom(int direction);
    void doit();
    QTextBrowser *lines;
    QProgressBar *state;
    int roomno;
    inline int randomnumber(int border){
        return rand()%border;
    }
public:
    ZorkUL(QTextBrowser *browser, QProgressBar *progress);
	void play();
	string go(string direction);
    void teleport();
    Board *myEnv;
    hero *theseus;
    void appendtolines(string input);
    void collect();
    void updatestatus();
    void setitem(int roomborder, Item* item);
    void setcharacter(int roomborderbottom, Character* character, Item* it);


};

#endif /*ZORKUL_H_*/
