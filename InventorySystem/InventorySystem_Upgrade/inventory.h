#pragma once
#pragma once
#include <string>
#include <iostream>
#include <algorithm>

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
		cout << "인벤토리 생성 완료" << endl;
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other)
	{
		pItems_(nullptr);
		Assign(other);
	}

	void Assign(const Inventory<T>& other)
	{
		T* newItems = new T[other.capacity_];

		for (int i = 0; i < other.size_; ++i)
		{
			newItems[i] = other.pItems_[i];
		}

		delete[] pItems_;

		pItems_ = newItems;
		capacity_ = other.capacity_;
		size_ = other.size_;
		cout << "인벤토리 복사 완료" << endl;
	}

	void Resize(int newCapacity)
	{
		if (newCapacity <= capacity_) return;

		T* newItems = new T[newCapacity];
		for (int i = 0; i < size_; ++i)
		{
			newItems[i] = pItems_[i];
		}

		delete[] pItems_;
		pItems_ = newItems;
		capacity_ = newCapacity;
		std::cout << "인벤토리 용량 확장" << capacity_ << std::endl;
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
			Resize(2 * capacity_);
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

	template <typename Compare>
	void SortItems(Compare comp)
	{
		// 시작 포인터부터 끝 포인터(시작 + 개수)까지 정렬
		sort(pItems_, pItems_ + size_, comp);
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};