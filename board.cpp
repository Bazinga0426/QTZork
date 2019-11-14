#include "board.h"

using namespace std;

bool Board::single=true;
Board* Board::instance=NULL;

Board* Board::createInstance(int w, int h)  //Singleton-Design-Pattern: Only One Board can exist
{
    if (single)
    {
        instance=new Board(w, h);
        instance->buildenviro();
        single=false;
    }
    return instance;
}

Board::Board(int w, int h){
    width=w;
    height=h;
    firstRoom=NULL;
    recRoom=NULL;
    prevRoom=NULL;
    rowstart=NULL;
    aboveRoom=NULL;
    roomnumber=width*height;
}

int Board::getroomnumber(){
    return  roomnumber;
}
int Board::getheight(){
    return this->height;
}

int Board::getwidth(){
    return this->width;
}

Room* Board::getrecRoom(){
    return this->recRoom;
}

Room* Board::getfirstRoom(){
    return this->firstRoom;
}

void Board::buildenviro(){
    Room* start= new Room;
    this->firstRoom=start;
    this->recRoom=start;
    int i, j, width, height, iwidth, num;
    width=this->width;
    height=this->height;
    num=0;
    iwidth=width-1;

    cout <<"Building Board..." << endl;
    cout <<"Height:" <<this->getheight() << endl;
    cout <<"Width:" <<this->getwidth() <<endl;
    for(i=0; i<height; i++){
        for(j=0; j<width;j++){
            this->recRoom->setrow(i);
            this->recRoom->setcol(j);

            Room* tmp=new Room;
            tmp->setDescription(j,i);
            if(j!=iwidth){

                this->recRoom->seteast(tmp);

            }

            if(j!=0){
                this->recRoom->setwest(this->prevRoom);
            }

            if(i>0){
                if(j==0){
                    this->aboveRoom=this->rowstart;
                }
                this->recRoom->setnorth(this->aboveRoom);
                this->aboveRoom->setsouth(this->recRoom);
                this->aboveRoom=this->aboveRoom->geteast();
            }


            if(j==0){
                this->rowstart=this->recRoom;
            }
            cout <<" " << this->recRoom->getrow() << this->recRoom->getcol(); //Shows Room_placement
            this->prevRoom=this->recRoom;
            this->recRoom=tmp;
            this->roomlist[num]=tmp;
            num++;

        }

        cout << endl; //Breaks rows
    }
    int tmp=(this->width*this->height)-1;
    Room *temp;
    temp=roomlist[tmp];
    temp->setmasterroom();
    cout << "Building Board success!" <<endl;
}

Room* Board::goeast(Room *tmp){
        tmp=tmp->geteast();
    return tmp;
}


Room* Board::gowest(Room *tmp){
    tmp=tmp->getwest();
    return tmp;
}

Room* Board::gosouth(Room *tmp){
    tmp=tmp->getsouth();
    return tmp;
}

Room* Board::gonorth(Room *tmp){
    tmp=tmp->getnorth();
    return tmp;
}


/*
void Board::placeinitial(){
    cout << "Initialising..."<<endl;
    int w=this->width;
    int h=this->height;
    Room *tmp;
    tmp=this->firstRoom;
    srand(time(NULL));
    while (tmp->getcol()!=round(w/2)){
        tmp=tmp->geteast();
    }
    while (tmp->getrow()!=round(h/2)){
            tmp=tmp->getsouth();
        }


}
*/
