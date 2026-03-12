#pragma once
#include <iostream>
#include <string>

using namespace std;

class Monster;

class Player {
public:
	Player(string nickname);

	virtual void attack() = 0;
	void printPlayerStatus();

	// getter 함수
	string getJobName() { return job_name; }
	string getNickname() { return nickname; }
	int getLevel() { return level; }
	int getHP() { return HP; }
	int getMP() { return MP; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	int getAccuracy() { return accuracy; }
	int getSpeed() { return speed; }

	// setter 함수
	void setNickname(string newNickname) { nickname = newNickname; }
	void setHP(int newHP) { HP = newHP; }
	void setMP(int newMP) { MP = newMP; }
	void setPower(int newPower) { power = newPower; }
	void setDefence(int newDefence) { defence = newDefence; }
	void setAccuracy(int newAccuracy) { accuracy = newAccuracy; }
	void setSpeed(int newSpeed) { speed = newSpeed; }

protected:
	string job_name;
	string nickname;
	int level;
	int HP;
	int MP;
	int power;
	int defence;
	int accuracy;
	int speed;
};