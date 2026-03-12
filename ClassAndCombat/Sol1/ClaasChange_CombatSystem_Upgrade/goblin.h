#pragma once
#include <string>
#include "monster.h"

using namespace std;

class Goblin : public Monster {
public:
    Goblin(string name);

    void attack();
};