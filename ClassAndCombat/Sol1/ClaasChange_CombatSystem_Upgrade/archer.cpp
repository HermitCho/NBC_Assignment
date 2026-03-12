#pragma once
#include "archer.h"
#include "monster.h"
#include <iostream>
#include <string>
using namespace std;

Archer::Archer(string newNickname) : Player(newNickname) {
	nickname = newNickname;
	job_name = "궁수";
	level = 1;
	HP = 80;
	MP = 110;
	power = 10;
	defence = 8;
	accuracy = 70;
	speed = 11;
	cout << "* 궁수로 전직하였습니다." << endl;
}

void Archer::attack(Monster* monster) {
	int realDamage = power - monster->getDefence() > 0 ? power - monster->getDefence() : 0;

	monster->setHP(monster->getHP() - realDamage);

	cout << "=================================================================================================" << endl;
	cout << "활을 쏴서 \"" << monster->getName() << "\"에게 " << realDamage << " 데미지를 입혔습니다. " << "적 남은 체력 : " << monster->getHP() << endl;
	cout << "=================================================================================================" << endl;
}