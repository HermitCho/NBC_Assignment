#pragma once
#include "warrior.h"
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

void Warrior::attack() {
    cout << "검을 휘두른다!" << endl;
}