#pragma once
#include <string>
#include "player.h"

using namespace std;

class Monster;

class Archer : public Player {
public:
    Archer(string nickname);

    void attack(Monster* monster);
};