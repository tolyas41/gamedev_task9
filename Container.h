#pragma once
#include <memory>
#include <vector>
#include <fstream>

template <typename T>
class Container
{
	size_t Size = 0;
	size_t Capacity = 0;
	std::unique_ptr<T[]> DataPtr = std::make_unique<T[]>(Size);
	std::vector<std::string> Actions;
	friend class ActionFunctor;

public:

	Container();
	~Container();

	void LoadAction();

	void PushBack(const T& obj);

	void PushBack(T&& obj);

	void PopBack();

	T& EmplaceBack(int data, size_t rows, size_t columns);

	size_t GetSize() const;

	void DeleteT(size_t index);

	T& operator[] (size_t index);

	void PrintMatrices();

	T Calculate();

	//test foo
	void PrintActions();

private:

	void ReAllocation(size_t newCapacity);

};

#include "Container.inl"
