
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <vector>

class Room {
private:
    std::string name;
    std::string description;
    std::vector<Room*> neighbors;


public:
    Room(const std::string&, const std::string& description);

    void addNeighbor(Room* room);
    std::vector<Room*> getNeighbors() const;

    std::string getName() const;
    std::string getDescription() const;

};



#endif
