
#include <iostream>
#include "Pet.h"
#include "Cat.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include "helper.h"



int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int currentRoomIndex=0;
    const int totalRooms  = 3;

    // Pointers to derived class objects
    Pet* myCat = new Cat("Kitty", 3, 4, 20, 10, 5,50, "Laser toy", 1);
    Pet* myCatBAD = new Cat("BAD Kitty", 3, 4, 20, 10, 5,50, "Laser toy", 1);
    Room* livingRoom = new Room ("Living Room", "A cozy place with a scratching post.");
    Room* kitchen = new Room ("Kitchen", "Smells like fish.");
    Room* garden = new Room ("Garden", "Sunny and full of birds.");
    std::vector<Room*> rooms = {livingRoom, kitchen, garden};

    livingRoom->addNeighbor(kitchen);
    kitchen->addNeighbor(garden);
    garden->addNeighbor(livingRoom);

    myCat->setCurrentRoom(livingRoom);
    std::vector<Room*> options = myCat->getCurrentRoom()->getNeighbors();
    myCat->moveTo(options[0]);

    auto enemies = loadEnemies("enemies.csv");
    

    while (currentRoomIndex < totalRooms)
    {
        Pet* player = myCat;

        std::cout<<"You are in "<< rooms[currentRoomIndex]->getName()<< "\n";

        std::cout<<"[Moving across room...]"<< "\n";

        char input;
        std::cout<<"Press 'f' to fight: ";
        std::cin>>input;
        if(input=='f'){
            std::cout <<"Entering fight!\n";
            std::vector<Pet*> fighters;
            fighters.push_back(myCat);
            fighters.insert(fighters.end(), enemies.begin(), enemies.end());

            runBattle(fighters); //define
        }

        std::cout << "[Walking to door...]\n";

        std::cout << "[Press 'e' to open door...]\n";
        std::cin>>input;
        if(input == 'e'){
            std::cout<<"Opening door...\n";
            currentRoomIndex++;
            if(currentRoomIndex < totalRooms){
                player->moveTo(rooms[currentRoomIndex]);
            }
            else{
                std::cout<< "Last Room reached. Game Over.";
                break;
            }
        }
    }


    //end1
    
}
