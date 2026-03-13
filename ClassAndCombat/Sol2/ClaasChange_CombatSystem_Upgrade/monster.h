#pragma once
#include <iostream>
#include <string>

class Player;

class Monster
{
public:
	Monster(string newName);
	void attack(Player* player);

	// getter 함수
	string getName() { return name; }
	int getHP() { return HP; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	int getSpeed() { return speed; }

	// setter 함수
	void setNickname(string newName) { name = newName; }
	void setHP(int newHP) { HP = newHP; }
	void setPower(int newPower) { power = newPower; }
	void setDefence(int newDefence) { defence = newDefence; }
	void setSpeed(int newSpeed) { speed = newSpeed; }

protected:
	string name;
	int HP;
	int power;
	int defence;
	int speed;
};