#include <fstream>
#include <sstream>
#include <iostream>
#include "Pet.h"
#include "Cat.h"
#include <cstdlib>
#include <ctime>
#include <queue>




std::vector<Pet*> loadEnemies(const std::string& filename) {
    std::vector<Pet*> enemies;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return enemies;
    }

    std::string line;
    // (Optional) skip header:
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string token;

        std::string name, toy;
        int age, lvl, atk, def, spd, hp, tails;

        // parse CSV tokens one by one
        std::getline(ss, name, ',');
        ss >> age;       ss.ignore(1);
        ss >> lvl;       ss.ignore(1);
        ss >> atk;       ss.ignore(1);
        ss >> def;       ss.ignore(1);
        ss >> spd;       ss.ignore(1);
        ss >> hp;        ss.ignore(1);

        // toy -> trim leading space and quotes
        std::getline(ss, toy, ',');
        if (!toy.empty() && toy.front()==' ') toy.erase(0,1);
        if (toy.front()=='"') toy = toy.substr(1, toy.size()-2);

        ss >> tails;

        // construct a new Cat (species="Cat" is set in Cat ctor)
        enemies.push_back(
            new Cat(name, age, lvl, atk, def, spd, hp, toy, tails)
        );
    }

    return enemies;
}
struct SpeedCompare{
    bool operator()(Pet* a, Pet* b){
        return a->getSpeed() < b->getSpeed();
    }

};

void runBattle(std::vector<Pet*>& fighters) {
    std::priority_queue<Pet*, std::vector<Pet*>, SpeedCompare> turnQueue;
    for (auto p : fighters)
        if (p->getHealth() > 0)
            turnQueue.push(p);

    while (true) {
        std::priority_queue<Pet*, std::vector<Pet*>, SpeedCompare> nextQueue;

        while (!turnQueue.empty()) {
            Pet* attacker = turnQueue.top();
            turnQueue.pop();
            if (attacker->getHealth() <= 0) 
                continue;

            // Show stats
            attacker->printInfo();

            // 1) Buff via mutate
            if (auto cat = dynamic_cast<Cat*>(attacker)) {
                cat->mutate();
            }

            // 2) Pick a defender
            Pet* defender = nullptr;
            for (auto p : fighters) {
                if (p != attacker && p->getHealth() > 0) {
                    defender = p;
                    break;
                }
            }

            // 3) Attack
            if (defender) {
                attacker->fight(*defender);
            }

            nextQueue.push(attacker);
        }

        // 4) Count who’s left alive
        int alive = 0;
        for (auto p : fighters)
            if (p->getHealth() > 0)
                ++alive;
        if (alive <= 1)
            break;

        turnQueue = std::move(nextQueue);
    }

    std::cout << "Battle over!\n";
}