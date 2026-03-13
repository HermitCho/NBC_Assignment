#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"

int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>(10);

	for (int i = 0; i < 11; ++i) //10칸 이상
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), (10 - i) * 100));
	}

	std::cout << "\n--- 정렬 전 출력 ---" << std::endl;
	itemInventory->PrintAllItems();

	itemInventory->SortItems(compareItemsByPrice);

	std::cout << "\n--- 정렬 후 출력 ---" << std::endl;
	itemInventory->PrintAllItems();

	delete itemInventory;
	return 0;
}