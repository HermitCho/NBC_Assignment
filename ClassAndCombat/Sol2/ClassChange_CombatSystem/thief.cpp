#include "thief.h"
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

void Thief::attack() {
	cout << "단검을 휘두른다!" << endl;
}