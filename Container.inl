#pragma once
#include "Container.h"
#include <iostream>

template <typename T>
Container<T>::Container()
{
	ReAllocation(2);
}

template <typename T>
Container<T>::~Container()
{
	DataPtr.release();
}

template <typename T>
void Container<T>::LoadAction()
{
	std::ifstream file;
	file.open("actions.txt");
	std::string line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			Actions.push_back(line);
		}
	}
	file.close();
}

template <typename T>
void Container<T>::PushBack(const T& obj)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	DataPtr[Size] = obj;
	Size++;
}

template <typename T>
void Container<T>::PushBack(T&& obj)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	DataPtr[Size] = std::move(obj);
	Size++;
}

template <typename T>
void Container<T>::PopBack()
{
	if (Size > 0)
	{
		Size--;
		DataPtr[Size].~T();
	}
}

template <typename T>
T& Container<T>::EmplaceBack(int data, size_t rows, size_t columns)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	DataPtr[Size] = T(data, rows, columns);
	return DataPtr[Size++];
}

template <typename T>
size_t Container<T>::GetSize() const
{
	return Size;
}

template <typename T>
void Container<T>::DeleteT(size_t index)
{
	if (index >= 0 && index < Size)
	{
		for (size_t i = 1; i < (Size - index); i++)
			DataPtr[index + i - 1] = DataPtr[index + i];
		DataPtr[Size - 1].~T();
		Size--;
	}
}

template <typename T>
T& Container<T>::operator[] (size_t index)
{
	return DataPtr[index];
}

template <typename T>
void Container<T>::PrintMatrices()
{
	for (size_t i = 0; i < Size; i++)
	{
		DataPtr[i].print_array();
	}
}

template <typename T>
T Container<T>::Calculate()
{
	T result = DataPtr[0];
	size_t i = 1;
	for (std::string action : Actions)
	{
		switch (action[0])
		{
		case '+':
			result += DataPtr[i];
			break;
		case '-':
			result -= DataPtr[i];
			break;
		case '*':
			result *= DataPtr[i];
			break;
		case '/':
			result /= DataPtr[i];
			break;
		default:
			std::cout << "\nERR: wrong symbols in file! acceptable only:\n+-/*\n";
			return result;
		}
		++i;
		if (i >= Size)
		{
			return result;
		}
	}
	return result;
}


template <typename T>
void Container<T>::ReAllocation(size_t newCapacity)
{
	std::unique_ptr<T[]> newBlock = std::make_unique<T[]>(newCapacity);

	if (newCapacity < Size)
		Size = newCapacity;

	for (size_t i = 0; i < Size; i++)
		newBlock[i] = DataPtr[i];
	DataPtr = std::move(newBlock);
	Capacity = newCapacity;
}


//test foo
template <typename T>
void Container<T>::PrintActions()
{
	std::cout << "Container's Actions are : \n";
	for (auto a : Actions)
		std::cout << a << " ";
	std::cout << "\n";
}