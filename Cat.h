
#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "Pet.h"


class Cat : public Pet{
    private:
    std::string favoriteToy;
    int numTails;
    Room* currentRoom;

    public:
    // Constructor
    Cat(const std::string& name, int age, int mutation_level, int attack, int defense, int speed, int health, std::string favoriteToy, int numTails);

    void printInfo() const override;
    void makeSound() const override;
    virtual void mutate() override;

    virtual ~Cat();


};

#endif