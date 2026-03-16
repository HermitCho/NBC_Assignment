#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "PotionRecipe.h"

using namespace std;

class AlchemyWorkshop
{
public:

	void addRecipe(PotionRecipe* v)
	{
		recipes.push_back(v);
		cout << "===============================================" << endl;
		cout << "물약 레시피 추가 : " << recipes[recipes.size()-1]->potionName << endl;
		cout << "===============================================" << endl;
	}

	void displayAllRecipes()
	{
		cout << "===============================================" << endl;
		cout << "물약 레시피) " << endl;
		for (PotionRecipe* recipe : recipes)
		{
			cout << "물약 이름 : " << recipe->potionName << endl;
			cout << "물약 재료 : " << endl;
			for (int j = 0; j < recipe->ingredients.size(); ++j)
			{
				cout << j+1 << ". " << recipe->ingredients[j] << endl;
			}
		}
		cout << "===============================================" << endl;
	}

	PotionRecipe* searchRecipeByName(const string& name)
	{
		for (PotionRecipe* recipe : recipes)
		{
			if (recipe->potionName == name)
			{
				cout << "===============================================" << endl;
				cout << "[검색 성공] 물약 레시피 정보" << endl;
				cout << " * 물약 이름 : " << recipe->potionName << endl;
				cout << " * 물약 재료 : ";
				for (const string& ingredient : recipe->ingredients)
				{
					cout << ingredient << " ";
				}
				cout << endl << "===============================================" << endl;

				return recipe;
			}
		}

		cout << "===============================================" << endl;
		cout << "[검색 실패] '" << name << "' 레시피를 찾을 수 없습니다." << endl;
		cout << "===============================================" << endl;
		return nullptr;
	}


	vector<PotionRecipe*> searchRecipeByIngredient(const string& ingredient)
	{
		vector<PotionRecipe*> foundRecipes;

		for (PotionRecipe* recipe : recipes)
		{
			for (const string& item : recipe->ingredients)
			{
				if (item == ingredient)
				{
					foundRecipes.push_back(recipe);
					break;
				}
			}
		}

		cout << "===============================================" << endl;
		if (foundRecipes.empty())
		{
			cout << "[검색 실패] '" << ingredient << "'(이)가 들어간 레시피가 없습니다." << endl;
		}
		else
		{
			cout << "[검색 성공] '" << ingredient << "'(이)가 들어간 레시피 목록:" << endl;
			for (PotionRecipe* found : foundRecipes)
			{
				cout << " - " << found->potionName << endl;
			}
		}
		cout << "===============================================" << endl;

		return foundRecipes;
	}

private:
	vector<PotionRecipe*> recipes;
};
