#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Pet.h"
#include "Cat.h"

// Compare by speed for priority queue
struct SpeedCompare {
    bool operator()(Pet* a, Pet* b) const {
        return a->getSpeed() < b->getSpeed();
    }
};

// Load enemies from CSV (unchanged)
std::vector<Pet*> loadEnemies(const std::string& filename) {
    std::vector<Pet*> enemies;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return enemies;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string name, toy;
        int age, lvl, atk, def, spd, hp, tails;

        std::getline(ss, name, ',');
        ss >> age; ss.ignore();
        ss >> lvl; ss.ignore();
        ss >> atk; ss.ignore();
        ss >> def; ss.ignore();
        ss >> spd; ss.ignore();
        ss >> hp; ss.ignore();
        std::getline(ss, toy, ',');
        if (!toy.empty() && toy.front()==' ') toy.erase(0,1);
        if (toy.size()>1 && toy.front()=='"' && toy.back()=='"')
            toy = toy.substr(1, toy.size()-2);
        ss >> tails;

        enemies.push_back(new Cat(name, age, lvl, atk, def, spd, hp, toy, tails));
    }
    return enemies;
}

// Collect all living opponents of 'attacker'
static std::vector<Pet*> getOpponents(Pet* attacker, const std::vector<Pet*>& fighters) {
    std::vector<Pet*> opps;
    for (auto* p : fighters)
        if (p != attacker && p->getHealth() > 0)
            opps.push_back(p);
    return opps;
}

// Let human player pick a defender; AI picks random
static Pet* chooseDefender(Pet* attacker, Pet* player, const std::vector<Pet*>& opponents) {
    if (attacker == player) {
        std::cout << "\nChoose your target:\n";
        for (size_t i = 0; i < opponents.size(); ++i) {
            std::cout << "  [" << (i+1) << "] "
                      << opponents[i]->getName()
                      << " (HP=" << opponents[i]->getHealth() << ")\n";
        }
        size_t choice = 0;
        do {
            std::cout << "Enter choice (1-" << opponents.size() << "): ";
            std::cin >> choice;
        } while (choice < 1 || choice > opponents.size());
        return opponents[choice - 1];
    }
    return opponents[std::rand() % opponents.size()];
}

// Conduct a back-and-forth duel (speed decides who strikes first).
// Returns true if defender died, false if attacker died.
// Exits early (returns immediately) if player chooses to flee.
static bool duel(Pet* attacker, Pet* defender, Pet* player) {
    std::cout << "\n-- Locked duel: "
              << attacker->getName() << " vs. "
              << defender->getName() << " --\n\n";

    // Decide who goes first
    Pet *first, *second;
    if (attacker->getSpeed() >= defender->getSpeed()) {
        first = attacker;  second = defender;
    } else {
        first = defender;  second = attacker;
    }

    // Alternate turns
    while (first->getHealth() > 0 && second->getHealth() > 0) {
        for (Pet* cur : { first, second }) {
            if (cur->getHealth() <= 0) break;

            // If it's the player's turn, allow attack or flee
            if (cur == player) {
                char cmd;
                do {
                    std::cout << "[A]ttack or [E]xit? ";
                    std::cin >> cmd;
                } while (cmd!='A' && cmd!='a' && cmd!='E' && cmd!='e');

                if (cmd=='E' || cmd=='e') {
                    std::cout << "You fled!\nBattle over!\n";
                    std::exit(0);
                }
            }

            // Perform the attack
            Pet* target = (cur == first) ? second : first;
            cur->fight(*target);
            std::cout << "\n";

            if (auto cat = dynamic_cast<Cat*>(cur)) {
                int lvl = cat->getMutationLevel() + 1;
                cat->setMutationLevel(lvl);
                if (lvl == 5) {
                    std::cout << cat->getName() << " hits mutation level 5 — MUTATE!\n";
                    cat->mutate();   // this is your full buff routine (tails, speed, etc)
                    cat->setMutationLevel(1);
                }

                std::cout 
                  << cat->getName() 
                  << "'s mutation level is now " 
                  << cat->getMutationLevel() 
                  << "\n\n";
            }

            // Show the target's updated stats
            target->printInfo();
            std::cout << "\n";

            // If someone died, end the duel
            if (target->getHealth() <= 0) {
                // return true if defender (second when attacker==first) fell
                return (cur == first);
            }
        }
    }

    return false; // should never reach here
}


void runBattle(std::vector<Pet*>& fighters) {
    srand((unsigned)time(nullptr));
    Pet* player = fighters.front();
    
    // Build initial turn order
    std::priority_queue<Pet*, std::vector<Pet*>, SpeedCompare> pq;
    for (auto* p : fighters)
        if (p->getHealth() > 0)
            pq.push(p);

    // Main loop
    while (!pq.empty()) {
        Pet* attacker = pq.top(); pq.pop();
        if (attacker->getHealth() <= 0) continue;

        // Show stats & mutate if cat
        attacker->printInfo();

        // Choose defender
        auto opponents = getOpponents(attacker, fighters);
        if (opponents.empty()) {
            std::cout << "Battle over!\n";
            return;
        }
        Pet* defender = chooseDefender(attacker, player, opponents);

        // Duel — returns true if defender died, false if attacker died
        bool defenderFell = duel(attacker, defender, player);

        // Announce and end
        if (defenderFell) {
            std::cout << defender->getName() << " has been defeated!\n";
        } else {
            std::cout << attacker->getName() << " has fallen!\n";
        }
        std::cout << "Battle over!\n";
        return;
    }
}
