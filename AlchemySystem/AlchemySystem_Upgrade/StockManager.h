#pragma once
#include <map>
#include <string>
#include <iostream>
#include <stdbool.h>
#include "PotionRecipe.h"

using namespace std;


class StockManager
{
public:
	void initializeStock(string potionName)
	{
		potionStock[potionName] = 3;
		return;
	}

	bool dispensePotion(string potionName)
	{
		for (auto& pair : potionStock)
		{
			auto it = potionStock.find(potionName);
			if (it != potionStock.end() && it->second >= 1)
			{ 
				--pair.second;
				cout << "=====================&&=========================" << endl;
				cout << "보관 중인 " << pair.first <<" 1개 가져감!" << endl;
				cout << "남은 " << pair.first << " : " << pair.second << "개" << endl;
				cout << "===============================================" << endl << endl;
				return true;
			}
			else
			{
				cout << "보관 중인 해당 물약이 없습니다! " << endl << endl;
				return false;
			}
		}
	}

	void returnPotion(string potionName)
	{
		potionStock[potionName] > MAX_STOCK ? MAX_STOCK : (potionStock[potionName] + 1);
		cout << "-----------------------&&-----------------------" << endl;
		cout << "물약 반납 완료! " << endl;
		cout << "------------------------------------------------" << endl << endl;
		return;
	}

	int getStock(string potionName)
	{

		return 0;
	}

private:
	map<string, int> potionStock;
	const int MAX_STOCK = 3;
};