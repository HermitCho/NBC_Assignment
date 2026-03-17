#pragma once
#include <set>
#include "AlchemyWorkshop.h"
#include "StockManager.h"

using namespace std;

void searchAndDespensePotion(AlchemyWorkshop* aw, StockManager* stock, string text);

int main()
{
	PotionRecipe* recipe1 = new PotionRecipe("HP물약", { "요정 호수의 물", "여린 샛잎", "마법 가루" });
	PotionRecipe* recipe2 = new PotionRecipe("MP물약", { "요정 호수의 물", "마른 박쥐 날개", "마법 가루" });
	PotionRecipe* recipe3 = new PotionRecipe("힘의 물약", { "힘의 여신의 성수", "금가루" });

	StockManager* stock = new StockManager;
	AlchemyWorkshop* workshop = new AlchemyWorkshop();


	workshop->addRecipe(recipe1);
	workshop->addRecipe(recipe2);
	workshop->addRecipe(recipe3);

	workshop->displayAllRecipes();
	workshop->searchRecipeByName("HP물약");
	workshop->searchRecipeByName("신속의 물약"); //없음
	workshop->searchRecipeByIngredient("마법 가루");
	workshop->searchRecipeByIngredient("두꺼운 쥐꼬리"); //없음


	stock->initializeStock("HP물약");
	searchAndDespensePotion(workshop, stock, "HP물약");
	searchAndDespensePotion(workshop, stock, "금가루"); //없음
	stock->initializeStock("힘의 물약");
	searchAndDespensePotion(workshop, stock, "금가루");


	delete workshop;
	delete workshop;
}

//void deleteWorkshop(AlchemyWorkshop* workshop)
//{
//	delete workshop;
//}



void searchAndDespensePotion(AlchemyWorkshop* aw, StockManager* stock, string text)
{
	set<string> s;

	PotionRecipe* foundByName = aw->searchRecipeByName(text);
	if (foundByName != nullptr)
	{
		s.insert(foundByName->potionName);
	}

	if (s.empty())
	{
		vector<PotionRecipe*> foundByIngred = aw->searchRecipeByIngredient(text);
		for (PotionRecipe* potion : foundByIngred)
		{
			s.insert(potion->potionName);
		}
	}

	for (string str : s)
	{
		stock->dispensePotion(str);
	}
}