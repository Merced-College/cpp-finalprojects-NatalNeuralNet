
#include <iostream>
#include "Pet.h"
#include "Cat.h"
#include <cstdlib>
#include <ctime>


int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Pointers to derived class objects
    Pet* myCat = new Cat("Kitty", 3, 4, 20, 10, 5,50, "Laser toy", 1);
    Pet* myCatBAD = new Cat("BAD Kitty", 3, 4, 20, 10, 5,50, "Laser toy", 1);
    Room* livingRoom = new Room ("Living Room", "A cozy place with a scratching post.");
    Room* kitchen = new Room ("Kitchen", "Smells like fish.");
    Room* garden = new Room ("Garden", "Sunny and full of birds.");
    
    livingRoom->addNeighbor(kitchen);
    kitchen->addNeighbor(garden);
    garden->addNeighbor(livingRoom);

    myCat->setCurrentRoom(livingRoom);
    std::vector<Room*> options = myCat->getCurrentRoom()->getNeighbors();
    myCat->moveTo(options[0]);
    
    
    
    
    
    
    
    bool turn= true;
    while (myCat->getHealth() > 0 && myCatBAD->getHealth() > 0) {
        if (turn){
        myCat->fight(*myCatBAD);
        myCat->mutate();
        }
        else{
            myCatBAD->fight(*myCat);
            myCatBAD->mutate();
        }
        if ((myCat->getSpeed())>myCatBAD->getSpeed()*2){
            myCatBAD->fight(*myCat);
            myCatBAD->mutate();
        }
        else{
            myCat->fight(*myCatBAD);
            myCat->mutate();
        }
        turn=!turn;
    }
}
