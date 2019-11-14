#include "enemy.h"

enemy::enemy(string description, int attackpoints, int healthpoints): Character ( description, attackpoints, healthpoints)
{

}


enemy::~enemy(){
    addmessage();
}

void enemy::addmessage(){
    message=message+"\nYour enemy has died an honorable death";
}

void enemy::act(Character& User){
    bool finished=false;
    int luck;
    double damage;
    double multi;
    while(!finished){
        luck=rand()%100;
        multi=rand()%4*0.5;
        if(luck<50){
            damage=getattack()*multi;
            if(User.getshield())
                damage=damage/2;
            takedamage<double>(User, damage);
        }
        else{
            damage=User.getattack()*multi;
            if(this->getshield())
                damage=damage/2;
            takedamage<double>(*this,damage);

        }
        if(!User.getstatus()){
            finished=true;
            setmessage("You were killed by a "+getdescription()+". Game over, bitch\n\n");
        }
        else if(!this->getstatus()){
            finished=true;
            setmessage("You defeated the "+getdescription()+". Maybe he has left something for you...");
        }
    }

}
