#pragma once
#include <string>
#include "player.h"

using namespace std;

class Archer : public Player {
public:
    Archer(string nickname);

    void attack();
};