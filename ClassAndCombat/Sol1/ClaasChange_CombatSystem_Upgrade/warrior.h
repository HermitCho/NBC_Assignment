#pragma once
#include <string>
#include "player.h"

using namespace std;

class Monster;

class Warrior : public Player {
public:
    Warrior(string nickname);

    void attack(Monster* monster);
};