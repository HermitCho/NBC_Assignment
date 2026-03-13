#pragma once
#include <string>
#include <iostream>

using namespace std;

// Item class 정의
class Item
{
public:

	Item() : name_(""), price_(0) {}

	Item(const std::string& name, int price) : name_(name), price_(price) {}

	const std::string& GetName() const;
	int GetPrice() const;
	void Clear()
	{
		name_ = "";
		price_ = 0;
	}
	// 정보를 출력하는 멤버 함수
	void PrintInfo() const
	{
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}

private:
	std::string name_;
	int price_;
};