#include "magician.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Magician::Magician(string newNickname) : Player(newNickname) {
	nickname = newNickname;
	job_name = "마법사";
	level = 1;
	HP = 80;
	MP = 120;
	power = 12;
	defence = 9;
	accuracy = 50;
	speed = 8;
	cout << "* 마법사로 전직하였습니다." << endl;
}

void Magician::attack(Monster* monster) {
	int realDamage = power - monster->getDefence() > 0 ? power - monster->getDefence() : 0;

	monster->setHP(monster->getHP() - realDamage);

	cout << "=================================================================================================" << endl;
	cout << "마법을 날려서 \"" << monster->getName() << "\"에게 " << realDamage << " 데미지를 입혔습니다. " << "적 남은 체력 : " << monster->getHP() << endl;
	cout << "=================================================================================================" << endl;
}