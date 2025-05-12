
#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>

class Pet {
private:
    std::string name;
    std::string species;
    int age;
    int hungerLevel; // 0 (full) to 10 (starving)

public:
    // Constructors
    Pet();
    Pet(const std::string& name, const std::string& species, int age, int hungerLevel);

    // Accessors (Getters)
    std::string getName() const;
    std::string getSpecies() const;
    int getAge() const;
    int getHungerLevel() const;

    // Mutators (Setters)
    void setName(const std::string& name);
    void setSpecies(const std::string& species);
    void setAge(int age);
    void setHungerLevel(int level);

    // CompareTo
    int compareTo(const Pet& other) const; // Returns -1, 0, or 1 based on name comparison

    // Output Function
    virtual void printInfo() const;
    //Other functions
    virtual void makeSound() const;
};



#endif
