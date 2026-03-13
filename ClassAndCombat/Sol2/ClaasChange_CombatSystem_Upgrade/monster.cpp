#include "player.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Monster::Monster(string newName) {
	name = newName;
	HP = 50;
	power = 30;
	defence = 0;
	speed = 10;
}

void Monster::attack(Player* player) {

	int realDamage = power - player->getDefence() > 0 ? power - player->getDefence() : 0;

	player->setHP(player->getHP() - realDamage);

	cout << "=================================================================================================" << endl;
	cout << "* " << name << "에게 공격받음, 남은 체력 : " << player->getHP() << endl;
	cout << "=================================================================================================" << endl;
}