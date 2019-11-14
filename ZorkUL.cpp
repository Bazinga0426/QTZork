#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#define size 5

using namespace std;
#include "ZorkUL.h"


ZorkUL::ZorkUL(QTextBrowser *browser, QProgressBar *progress) {
    createRooms();
    lines=browser;
    state=progress;
    roomno=myEnv->getroomnumber();
    srand(time(NULL));
    init();
}

void ZorkUL::init(){
    reset();
    Room *tmp;
    int  i;
    theseus=new hero("Theseus", 100, 100);
    updatestatus();
    currentRoom=myEnv->getfirstRoom();
    Item *copperkey=new key("copperkey", 0);
    Item *jadekey=new key("jadekey", 0);
    Item *crystalkey=new key("crystalkey", 0);
    Item *mastersword=new sword("Mastersword", 150);
    Item *knightsword=new sword("sword", 100);
    Item *aegis=new shield("aegis", 100);
    Item *knightshield=new shield("knightshield", 50);
    Item *light=new lantern("lantern", 0);
    Item *teleport=new medaillon("Medaillon", 0);
    Item *artdegree=new degree("artdegree", 0);
    enemy *Minotaur=new enemy("Minotaur", 120, 120);
    enemy *Medusa=new enemy("Medusa", 100, 50);
    enemy *Bystander=new enemy("Bystander", 50, 50);
    enemy *Typhon= new enemy("Typhon", 150, 150);
    Character *Fairy=new healer("Fairy", 0, 0);
    setitem(24, teleport);
    setitem(8, knightshield);
    setitem(10, knightsword);
    setitem(6, light);
    setitem(15, copperkey);
    setitem(24, jadekey);
    setcharacter(5, Typhon, mastersword);
    setcharacter(10, Minotaur, crystalkey);
    setcharacter(15, Medusa, aegis);
    setcharacter(18, Bystander, artdegree);
    setcharacter(15, Fairy, NULL);
    for(i=13; i<(roomno-1); i++){
        tmp=roomlist[i];
        tmp->setdarkness();
    }
    for(i=0; i<(roomno-1); i++){
        tmp=roomlist[i];
        tmp->setlongdescription();
    }
    currentRoom=myEnv->getfirstRoom();
}

void ZorkUL::setitem(int border, Item* item){
    int random;
    Room *tmp;
    random=randomnumber(border)+1;
    tmp=roomlist[random];
    if(!tmp->isItemInRoom())
        tmp->setItem(item);
    else
        setitem(border, item);
    cout<<"Created " << item->getDescription() << " in Room " << tmp->getrow() << tmp->getcol()<<endl;
}

void ZorkUL::setcharacter(int bordertop, Character *character, Item *it){
    int random;
    Room *tmp;
    int range=roomno-bordertop;
    random=randomnumber(bordertop);
    random=random+range;
    tmp=roomlist[random];
    if(!tmp->getcharacteruno()&&!tmp->isItemInRoom())
        tmp->setcharacteruno(character);
    else
        setcharacter(bordertop, character, it);
    tmp->setItem(it);
    cout<<"Created " << character->getdescription() << " in Room " << tmp->getrow() << tmp->getcol()<<endl;
}
void ZorkUL::reset(){
    Room *tmp;
    for(int i=0; i<25;i++){
        tmp=roomlist[i];
        tmp->reset();
    }
}

void ZorkUL::createRooms()  {
   myEnv=Board::createInstance(size, size);   //Creates 25 Fields Board
    int numr=myEnv->getwidth()*myEnv->getheight();

   for(int i=0; i<numr;i++){
       roomlist[i]=myEnv->roomlist[i];
   }

   currentRoom=myEnv->getfirstRoom();

}

void ZorkUL::play() {
    init();
    printHelp();
}


void ZorkUL::printHelp() {
    string help="Welcome to the maze of crete, the home of the mighty minotaurs!\n"
                "The evil King has thrown you into this death-trap, the exit is sealed with 3 keys\n"
                "While you are pretty strong, a sword and a shield could be helpful in the fights\n"
                "to come...maybe some of your predecessors left some?\n"
                "Some parts of the maze lay in the dark...a lantern would be handy there."
                "There are other secrets in this maze to be found...I wish you good luck";
    appendtolines(help);
}




void ZorkUL::teleport(){
    if(theseus->getteleport()){
            bool itworked=false;
            Room *tmp;
            int random=rand()%(size*size);
            tmp=roomlist[random];
            while(!itworked){
                if(tmp->getmasterroom()&&(this->theseus->getkey()<3)){
                    random=rand()%25;
                }
                else{
                    itworked=true;
                }
            }
            appendtolines("Teleported!");
            currentRoom=tmp;
    }
    else
        appendtolines("Y no wizzard, noob");
}

void ZorkUL::setroomlist(Room* tmp, int place){
    this->roomlist[place]=tmp;
}

void ZorkUL::changeroom(int direction){
    Room *tmp;
    switch(direction){
        case 1: tmp=this->currentRoom->getnorth();
        break;
        case 2: tmp=this->currentRoom->geteast();
        break;
        case 3: tmp=this->currentRoom->getsouth();
        break;
        case 4: tmp=this->currentRoom->getwest();
        break;
    default: tmp=this->currentRoom->getwest();
    }
    if(tmp==NULL){
        appendtolines("There is a wall there");
    }
    else{
        if(tmp->getmasterroom()&&(this->theseus->getkey()<3)){
            appendtolines("This room is locked");
        }
        else{
            this->currentRoom=tmp;
            cout<<"Moved into Room " <<currentRoom->getDescription()<<endl;
            updatestatus();
            appendtolines(currentRoom->action(*theseus));
            if(!theseus->getstatus()){
                appendtolines("You can't escape, even in death. Start again\n");
                play();
            }

        }
    }
}

void ZorkUL::updatestatus(){
    state->setValue(int(theseus->gethealth()));
}

void ZorkUL::appendtolines(string input){
    QString qstr=QString::fromStdString(input);
    lines->append(qstr);
}

void ZorkUL::collect(){
    string tmp=currentRoom->collectitem(*theseus);
    appendtolines(tmp);
}
