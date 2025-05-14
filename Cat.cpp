#include "Cat.h"
#include <cstdlib>
#include <ctime>


// Constructor calls Pet constructor with species set to "Dog"
Cat::Cat(const std::string& name, int age, int mutation_level, int attack, int defense, int speed, int health, std::string favoriteToy, int numTails)
    : Pet(name, "Cat", age, mutation_level, attack, defense, speed, health), favoriteToy(favoriteToy), numTails(numTails) {}

void Cat::printInfo() const {
    Pet::printInfo();  // Call the base class version
    //std::cout << "Favorite Toy: " << favoriteToy << std::endl;
    std::cout << "Number of Tails: " << numTails << std::endl;
    std::cout <<"\n";
}

void Cat::makeSound() const {
    std::cout << getName() << " meows: Meow meow!" << std::endl;
}

void Cat::mutate() {
    // 1) pick a stat index 0..4
    int statIdx = std::rand() % 4;
    // 2) pick bonus 1..3
    int bonus  = std::rand() % 3 + 1;

    // 3) apply via switch
    switch (statIdx) {
        case 0: // health
            setHealth(getHealth() + bonus * 10);
            numTails += bonus;
            std::cout << getName() 
                      << " mutates tails +" << bonus
                      << " → " << numTails << "\n";
            std::cout << getName() 
                      << " mutates health +" << (bonus*10)
                      << " → " << getHealth() << "\n";
            break;
        case 1: // attack
            setAttack(getAttack() + bonus);
            numTails += bonus;
            std::cout << getName() 
                      << " mutates tails +" << bonus
                      << " → " << numTails << "\n";
            std::cout << getName() 
                      << " mutates attack +" << bonus
                      << " → " << getAttack() << "\n";
            break;
        case 2: // defense
            setDefense(getDefense() + bonus);
            numTails += bonus;
            std::cout << getName() 
                      << " mutates tails +" << bonus
                      << " → " << numTails << "\n";
            std::cout << getName() 
                      << " mutates defense +" << bonus
                      << " → " << getDefense() << "\n";
            break;
        case 3: // speed
            setSpeed(getSpeed() + bonus);
            numTails += bonus;
            std::cout << getName() 
                      << " mutates tails +" << bonus
                      << " → " << numTails << "\n";
            std::cout << getName() 
                      << " mutates speed +" << bonus
                      << " → " << getSpeed() << "\n";
            
            break;
    }

}



Cat::~Cat() {}
