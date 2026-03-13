#include "warrior.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Warrior::Warrior(string newNickname) : Player(newNickname) {
	nickname = newNickname;
	job_name = "전사";
	level = 1;
	HP = 100;
	MP = 100;
	power = 10;
	defence = 10;
	accuracy = 50;
	speed = 10;
	cout << "* 전사로 전직하였습니다." << endl;
}

void Warrior::attack(Monster* monster) {

	int realDamage = power - monster->getDefence() > 0 ? power - monster->getDefence() : 0;

	monster->setHP(monster->getHP() - realDamage);

	cout << "=================================================================================================" << endl;
	cout << "검을 휘두둘러서 \""<< monster->getName() <<"\"에게 " << realDamage << " 데미지를 입혔습니다. " << "적 남은 체력 : " << monster->getHP() << endl;
	cout << "=================================================================================================" << endl;
}