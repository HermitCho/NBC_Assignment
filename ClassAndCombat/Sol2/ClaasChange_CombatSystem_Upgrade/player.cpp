#pragma once
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(string newNickname) {
	nickname = newNickname;
	job_name = " ";
	level = 1;
	HP = 100;
	MP = 100;
	power = 10;
	defence = 10;
	accuracy = 50;
	speed = 10;
}

void Player::printPlayerStatus() {
	cout << "------------------------------------" << endl;
	cout << "* 현재 능력치" << endl;
	cout << "닉네임: " << nickname << endl;
	cout << "Lv. " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "MP: " << MP << endl;
	cout << "공격력: " << power << endl;
	cout << "방어력: " << defence << endl;
	cout << "정확도: " << accuracy << endl;
	cout << "속도: " << speed << endl;
	cout << "------------------------------------" << endl;
}