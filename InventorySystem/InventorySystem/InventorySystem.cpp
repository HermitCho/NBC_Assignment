#pragma once
#include <iostream>
#include <string>
#include "inventory.h"
#include "item.h"

void main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();

	delete itemInventory;
}