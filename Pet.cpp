
#include "Pet.h"
#include <iostream>

// Default constructor
Pet::Pet() : name("Unnamed"), species("Unknown"), age(0), mutationLevel(3), attack(10), defense(10), speed(5), health(50) {}

// Parameterized constructor
Pet::Pet(const std::string& name, const std::string& species, int age, int mutationLevel, int attack, int defense, int speed, int health)
    : name(name), species(species), age(age), mutationLevel(mutationLevel), attack(attack), defense(defense), speed(speed), health(health) {}

// Accessors
std::string Pet::getName() const {
    return name;
}

std::string Pet::getSpecies() const {
    return species;
}

int Pet::getAttack() const {
    return attack;
}

int Pet::getDefense() const {
    return defense;
}

int Pet::getSpeed() const {
    return speed;
}

int Pet::getMutationLevel() const {
    return mutationLevel;
}

int Pet::getHealth() const {
    return health;
}

// Mutators
void Pet::setName(const std::string& name) {
    this->name = name;
}

void Pet::setSpecies(const std::string& species) {
    this->species = species;
}

void Pet::setAttack(int attack) {
    if (attack >= 0) {
        this->attack = attack;
    }
}
void Pet::setDefense(int defense) {
    if (defense >= 0) {
        this->defense = defense;
    }
}
void Pet::setSpeed(int speed) {
    if (speed >= 0) {
        this->speed = speed;
    }
}

void Pet::setHealth(int health) {
    if (health >= 0) {
        this->health = health;
    }
}

void Pet::setMutationLevel(int level) {
    if (level >= 0) {
        this->mutationLevel = level;
    }
}

// CompareTo
int Pet::compareTo(const Pet& other) const {
    if (name < other.name) return -1;
    if (name > other.name) return 1;
    return 0;
}

// Output
void Pet::printInfo() const {
    std::cout << "Pet Name: " << name << std::endl;
    std::cout << "Species: " << species << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Mutation Level: " << mutationLevel << "/10" << std::endl;
}

void Pet::makeSound() const {
    std::cout << name << " makes an undefined noise." << std::endl;
}

void Pet::fight(Pet& defender) const {
    std::cout <<getName()<<" ATTACKS"<< std::endl;
    int damage = getAttack() - defender.getDefense();
    int newHp = defender.getHealth() - damage;
    defender.setHealth(newHp > 0 ? newHp : 0);
    std::cout<<defender.getHealth()<<std::endl;
    
}

void Pet::setCurrentRoom(Room* room){
    currentRoom = room;
}
Room* Pet::getCurrentRoom() const{
    return currentRoom;
}
void Pet::moveTo(Room* newRoom){
    currentRoom = newRoom;
    std::cout<< getName() << " moved to " << newRoom->getName()<< "!\n";
}

void Pet::mutate(){}
Pet::~Pet() {}  // definition
