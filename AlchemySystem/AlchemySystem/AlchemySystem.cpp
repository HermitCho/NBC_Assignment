#pragma once
#include "AlchemyWorkshop.h"

int main()
{
	PotionRecipe* recipe1 = new PotionRecipe("HP물약", {"요정 호수의 물", "여린 샛잎", "마법 가루" });
	PotionRecipe* recipe2 = new PotionRecipe("MP물약", { "요정 호수의 물", "마른 박쥐 날개", "마법 가루" });
	PotionRecipe* recipe3 = new PotionRecipe("힘의 물약", { "힘의 여신의 성수", "금가루" });

	AlchemyWorkshop* workshop = new AlchemyWorkshop();

	workshop->addRecipe(recipe1);
	workshop->addRecipe(recipe2);
	workshop->addRecipe(recipe3);

	workshop->displayAllRecipes();
	workshop->searchRecipeByName("HP물약");
	workshop->searchRecipeByName("신속의 물약");
	workshop->searchRecipeByIngredient("마법 가루");
	workshop->searchRecipeByIngredient("두꺼운 쥐 꼬리");

	delete workshop;
}

//void deleteWorkshop(AlchemyWorkshop* workshop)
//{
//	delete workshop;
//}
