#include "Cat.h"
#include <cstdlib>
#include <ctime>


// Constructor calls Pet constructor with species set to "Dog"
Cat::Cat(const std::string& name, int age, int mutation_level, int attack, int defense, int speed, int health, std::string favoriteToy, int numTails)
    : Pet(name, "Cat", age, mutation_level, attack, defense, speed, health), favoriteToy(favoriteToy), numTails(numTails) {}

void Cat::printInfo() const {
    Pet::printInfo();  // Call the base class version
    std::cout << "Favorite Toy: " << favoriteToy << std::endl;
    std::cout << "Number of Tails: " << numTails << std::endl;
}

void Cat::makeSound() const {
    std::cout << getName() << " meows: Meow meow!" << std::endl;
}

void Cat::mutate(){


    int bonus = std::rand() % 3 + 1;
    numTails += bonus;
    setSpeed(getSpeed()+bonus);

    int newLevel = getMutationLevel() + 1;
    if (newLevel <= 5) 
        setMutationLevel(newLevel);
    else
        setMutationLevel(1);

    std::cout 
    << "Mutated: +" << bonus << std::endl
    << " tails → now " << numTails
    << ", speed=" << getSpeed()
    << ", level=" << getMutationLevel()
    << "\n";


    
}


Cat::~Cat() {}
