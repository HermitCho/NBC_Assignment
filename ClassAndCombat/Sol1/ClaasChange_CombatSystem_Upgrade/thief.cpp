#include "thief.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Thief::Thief(string newNickname) : Player(newNickname) {
	nickname = newNickname;
	job_name = "도적";
	level = 1;
	HP = 80;
	MP = 110;
	power = 10;
	defence = 8;
	accuracy = 60;
	speed = 12;
	cout << "* 도적으로 전직하였습니다." << endl;
}

void Thief::attack(Monster* monster) {
	int realDamage = power - monster->getDefence() > 0 ? power - monster->getDefence() : 0;

	monster->setHP(monster->getHP() - realDamage);

	cout << "=================================================================================================" << endl;
	cout << "단검을 휘두둘러서 \"" << monster->getName() << "\"에게 " << realDamage << " 데미지를 입혔습니다. " << "적 남은 체력 : " << monster->getHP() << endl;
	cout << "=================================================================================================" << endl;
}