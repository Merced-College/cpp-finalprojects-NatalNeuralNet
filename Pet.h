
#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>
#include "Room.h"

class Pet {
private:
    std::string name;
    std::string species;
    int age;
    int mutationLevel;
    int attack;
    int defense;
    int speed;
    int health;
    Room* currentRoom;

public:
    // Constructors
    Pet();
    Pet(const std::string& name, const std::string& species, int age, int mutationLevel, int attack, int defense, int speed, int health);

    // Accessors (Getters)
    std::string getName() const;
    std::string getSpecies() const;
    int getAge() const;
    int getMutationLevel() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;
    int getHealth() const;

    // Mutators (Setters)
    void setName(const std::string& name);
    void setSpecies(const std::string& species);
    void setAge(int age);
    void setMutationLevel(int level);
    void setAttack(int attack);
    void setDefense(int defense);
    void setSpeed(int speed);
    void setHealth(int health);

    // CompareTo
    int compareTo(const Pet& other) const; // Returns -1, 0, or 1 based on name comparison

    // Output Function
    virtual void printInfo() const;
    //Other functions
    virtual void makeSound() const;
    virtual void fight(Pet& defender) const;
    virtual void mutate();
    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;
    void moveTo(Room* newRoom);
    virtual ~Pet();  // declaration

};



#endif
