#pragma once
#include <string>
#include "player.h"

using namespace std;

class Monster;

class Magician : public Player {
public:
    Magician(string nickname);

    void attack(Monster* monster);
};