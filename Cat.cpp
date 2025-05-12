#include "Cat.h"

// Constructor calls Pet constructor with species set to "Dog"
Cat::Cat(const std::string& name, int age, int hunger_level, std::string favoriteToy, int numTails)
    : Pet(name, "Cat", age, hunger_level), favoriteToy(favoriteToy), numTails(numTails) {}

void Cat::printInfo() const {
    Pet::printInfo();  // Call the base class version
    std::cout << "Favorite Toy: " << favoriteToy << std::endl;
    std::cout << "Number of Tails: " << numTails << std::endl;
}

void Cat::makeSound() const {
    std::cout << getName() << " meows: Meow meow!" << std::endl;
}

