#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <string>

using namespace std;



class Character {
 protected:
	string description;
    string message;
    string type;
    int keys;
    int attack;
     double health;
      bool teleport;
      bool weapon;
     bool shield;
     bool status;
     bool lantern;




public:
    void operator +(int change);
    void operator -(double change);
    void operator -(int change);
    void setweapon();
    void setshield();
    void kill();
    void setinithealth(int init);
    void sethealth(double change);
    void setattack(int additionalattack);
    void setlantern();
    int getattack();
    double gethealth();
    virtual void act(Character& User)=0;
    Character(string description, int attackpoints, int healthpoints);
    virtual ~Character();
    string getdescription();
    bool getstatus();
    void setteleport();
    bool getshield();
    void setmessage(string message);
    string getmessage();
    bool getlantern();
    template<class T>
    void takedamage(Character& victim, T damage){
        victim-damage;
    }
    void addkey();
    int getkey();
    bool getteleport();

};

#endif /*CHARACTER_H_*/
