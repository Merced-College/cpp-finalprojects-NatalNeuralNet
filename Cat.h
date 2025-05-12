
#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "Pet.h"


class Cat : public Pet{
    private:
    std::string favoriteToy;
    int numTails;

    public:
    // Constructor
    Cat(const std::string& name, int age, int hunger_level, std::string favoriteToy, int numTails);

    void printInfo() const override;
    void makeSound() const override;

};

#endif