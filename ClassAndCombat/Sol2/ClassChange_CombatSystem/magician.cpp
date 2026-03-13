#pragma once
#include "magician.h"
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

void Magician::attack() {
	cout << "마법을 날린다!" << endl;
}