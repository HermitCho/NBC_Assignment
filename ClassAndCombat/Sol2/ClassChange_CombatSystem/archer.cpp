#pragma once
#include "archer.h"
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

void Archer::attack() {
	cout << "화살을 쏜다!" << endl;
}