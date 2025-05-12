
#include "Pet.h"

// Default constructor
Pet::Pet() : name("Unnamed"), species("Unknown"), age(0), hungerLevel(5) {}

// Parameterized constructor
Pet::Pet(const std::string& name, const std::string& species, int age, int hungerLevel)
    : name(name), species(species), age(age), hungerLevel(hungerLevel) {}

// Accessors
std::string Pet::getName() const {
    return name;
}

std::string Pet::getSpecies() const {
    return species;
}

int Pet::getAge() const {
    return age;
}

int Pet::getHungerLevel() const {
    return hungerLevel;
}

// Mutators
void Pet::setName(const std::string& name) {
    this->name = name;
}

void Pet::setSpecies(const std::string& species) {
    this->species = species;
}

void Pet::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    }
}

void Pet::setHungerLevel(int level) {
    if (level >= 0 && level <= 10) {
        hungerLevel = level;
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
    std::cout << "Hunger Level: " << hungerLevel << "/10" << std::endl;
}

void Pet::makeSound() const {
    std::cout << name << " makes an undefined noise." << std::endl;
}
