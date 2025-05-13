#include "Room.h"

Room::Room(const std::string& name, const std::string& description)
:name(name), description(description){}

void Room::addNeighbor(Room* room){
    neighbors.push_back(room);
}

std::vector<Room*> Room::getNeighbors() const{
    return neighbors;
}

std::string Room::getName() const{
    return name;
}
std::string Room::getDescription() const{
    return description;
}