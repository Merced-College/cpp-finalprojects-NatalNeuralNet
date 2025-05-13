
#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <string>
#include "Pet.h"

// Loads a CSV of enemy Cats (name, age, level, …, tails)
std::vector<Pet*> loadEnemies(const std::string& filename);

// Functor for priority‐queue by speed
struct SpeedCompare {
    bool operator()(Pet* a, Pet* b) const;
};

// Given a list of fighters, runs the turn‐based battle loop
void runBattle(std::vector<Pet*>& fighters);

#endif