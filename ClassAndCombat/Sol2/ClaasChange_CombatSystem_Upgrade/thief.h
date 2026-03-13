#pragma once
#include <string>
#include "player.h"

using namespace std;

class Monster;

class Thief : public Player {
public:
    Thief(string nickname);

    void attack(Monster* monster);
};