
#include <iostream>
#include "Pet.h"
#include "Cat.h"


int main() {

    // Base Pet Objects
    Pet pet1("Rex", "Dog", 3, 6);
    Pet pet2("Whiskers", "Cat", 2, 4);
    Cat pet4("Kitty", 3, 4, "Laser toy", 3);

    // Info Checks
    std::cout << "Pet 1 Info:\n";
    pet1.printInfo();

    std::cout << "\nPet 2 Info:\n";
    pet2.printInfo();

    // Derived Class info check
    std::cout << "\nPet 3 Info:\n";
    pet4.printInfo();

    // Pointers to derived class objects

    Pet* myCat = new Cat("Kitty", 3, 4, "Laser toy", 3);
    myCat->makeSound();



}
