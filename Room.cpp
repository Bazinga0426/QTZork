#include "Room.h"
#include "Command.h"
#include "enemy.h"


Room::Room(){
    north=NULL;
    west=NULL;
    east=NULL;
    south=NULL;
    iteminroom=false;
    col=0;
    row=0;
    uno=false;
    dark=false;
    ismasterroom=false;
    Items==NULL;
}

void Room::reset(){
    iteminroom=false;
    uno=false;
    dark=false;
    Items==NULL;
}

void Room::setdarkness(){
    dark=true;
}

bool Room::getdarkness(){
    return dark;
}

void Room::setDescription(int c, int r){
    this->description=to_string(r)+to_string(c);

}

string Room::getDescription(){
    return description;
}

int Room::setlongdescription(){
    if(dark){
        longdescription="This room is dark. You can't find any Items here, you also can't see if there are enemies in here";
        return 0;

    }
    else if(uno){
        longdescription="There is someone here...";
        return 0;

    }
    else if(iteminroom){
        longdescription="There seems to be something lying around.";
        return 0;
    }
    else{
        longdescription="This room has nothing special in it";
        return 0;
    }
}

void Room::setsouth(Room* s){
    this->south=s;
}

void Room::setnorth(Room* n){
    this->north=n;
}



void Room::setwest(Room* w){
    this->west=w;
}

void Room::seteast(Room* e){
    this->east=e;
}

Room *Room::geteast(){
    return this->east;
}

Room *Room::getnorth(){
    return this->north;
}

Room *Room::getsouth(){
    return this->south;
}

Room *Room::getwest(){
    return this->west;
}

void Room::setrow(int r){
    this->row=r;
}

void Room::setcol(int c){
    this->col=c;
}

int Room::getrow(){
    return this->row;
}

int Room::getcol(){
    return this->col;
}



void Room::setcharacteruno(Character *chara){
    this->Uno=chara;
    uno=true;
}

bool Room::getitem(){
    return this->iteminroom;
}

string Room::action(Character& Hero){
    if(dark && Hero.getlantern()){
        dark=false;
        setlongdescription();
    }

    if(dark && !Hero.getlantern()){

        return getlongdescription();
    }

    if(uno){
        cout<<"Here should be a character"<<endl;
        Uno->act(Hero);
        string tmp=Uno->getmessage();
        delete Uno;
        uno=false;
        setlongdescription();
        return tmp;
    }
    else if(ismasterroom){
        return "You win.";
    }
    else{
        return getlongdescription();
    }

}

string Room::collectitem(Character& hero){
    if(!iteminroom)
        return "Are you blind? There is nothing here...";
    Items->act(hero);
    string tmp=Items->getmessage();
    delete Items;
    Items=NULL;
    iteminroom=false;
    setlongdescription();
    return tmp;
}

void Room::setItem(Item *it){
    Items=it;
    iteminroom=true;
}

string Room::getlongdescription(){
    return longdescription;
}

bool Room::getcharacteruno(){
    return uno;
}

void Room::setmasterroom(){
    ismasterroom=true;
}

bool Room::isItemInRoom(){
    return iteminroom;
}

bool Room::getmasterroom(){
    return ismasterroom;
}
