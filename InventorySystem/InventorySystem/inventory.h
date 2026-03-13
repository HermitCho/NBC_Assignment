#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10)
	{
		size_ = 0;
		if (capacity <= 0)
		{	
			capacity = 1;
		}
		capacity_ = capacity;
		pItems_ = new T[capacity];
	}

	~Inventory()
	{
		if (pItems_ != nullptr)
		{
			delete[] pItems_;
			pItems_ = nullptr;
		}
	}

	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			cout << "인벤토리가 가득 찼습니다." << endl;
			return;
		}
		pItems_[size_] = item;
		++size_;
	}

	void RemoveLastItem()
	{
		if (size_ == 0)
		{
			cout << "인벤토리가 비어있습니다." << endl;
			return;
		}
		--size_;
	}

	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }
	void PrintAllItems() const
	{
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i].PrintInfo();
		}
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};