#pragma once
#include <string>
#include <vector>

using namespace std;

class PotionRecipe
{
public:
	PotionRecipe(const string& name, const vector<string>& ingred)
	{
		potionName = name;
		ingredients = ingred;
	}

	//¾èÀº º¹»ç
	string potionName;
	vector<string> ingredients;
};