#include "Character.h"

Character::Character(string descript, int attackpoints=100, int healthpoints=100):
    description(descript),
    attack(attackpoints),
    health(healthpoints),
    status(true),
    teleport(false),
    weapon(false),
    shield(false),
    lantern(false),
    type(""),
    message("")
{

}

Character::~Character(){
   // cout<<this->description+" died a honorable death"<<endl;
}

void Character::operator+(int change){
    health+=change;

}


void Character::operator-(double change){
    health-=change;
    if(health<=0)
        kill();
}

void Character::operator-(int change){
    health-=change;
    if(health<=0)
        kill();
}




void Character::setlantern(){
    this->lantern=true;
}
void Character::setweapon(){
    this->weapon=true;
}

void Character::setshield(){
    this->shield=true;
}

void Character::sethealth(double change){
    this->health+=change;
}

void Character::setattack(int add){
    this->attack+=add;
}

bool Character::getstatus(){
    return status;
}
void Character::setteleport(){
    teleport=true;
}

void Character::kill(){
    status=false;
}

int Character::getattack(){
    return attack;
}

void Character::setinithealth(int init){
    health=init;
}

void Character::setmessage(string mess){
    message=mess;
}

string Character::getmessage(){
    return  message;
}

bool Character::getlantern(){
    return lantern;
}

double Character::gethealth(){
    return health;
}

bool Character::getshield(){
    return shield;
}

void Character::addkey(){
    this->keys++;
}

int Character::getkey(){
    return this->keys;
}

string Character::getdescription(){
    return description;
}

bool Character::getteleport(){
    return teleport;
}



