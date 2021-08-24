#pragma once
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>

template <typename T>
class Container
{
	size_t Size = 0;
	size_t Capacity = 0;
	std::unique_ptr<std::unique_ptr<T>[]> DataArray = 
		std::unique_ptr<std::unique_ptr<T>[]>(new std::unique_ptr<T>[Size]);
	std::vector<std::string> Actions;
	friend class ActionFunctor;

public:

	Container()
	{
		ReAllocation(2);
	}

	~Container()
	{
		DataArray.release();
	}

	void LoadAction()
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

	void PushBack(const T& obj)
	{
		if (Size >= Capacity)
			ReAllocation(Capacity + Capacity / 2);

		*DataArray[Size] = std::move(obj);
		Size++;
	}

	void PushBack(T&& obj)
	{
		if (Size >= Capacity)
			ReAllocation(Capacity + Capacity / 2);

		*DataArray[Size] = std::move(obj);
		Size++;
	}

	void PopBack()
	{
		if (Size > 0)
		{
			Size--;
			*DataArray[Size].~T();
		}
	}

	T& EmplaceBack(int data, size_t rows, size_t columns)
	{
		if (Size >= Capacity)
			ReAllocation(Capacity + Capacity / 2);

		*DataArray[Size] = T(data, rows, columns);
		return *DataArray[Size++];
	}

	size_t GetSize() const
	{
		return Size;
	}

	void DeleteElement(size_t index)
	{
		if (index >= 0 && index < Size)
		{
			for (size_t i = 1; i < (Size - index); i++)
				DataArray[index + i - 1] = DataArray[index + i];
			DataArray[Size - 1].~T();
			Size--;
		}
	}

	T& operator[] (size_t index)
	{
		return DataArray[index];
	}

	void PrintMatrices()
	{
		for (size_t i = 0; i < Size; i++)
		{
			(*DataArray[i]).print_array();
		}
	}

	T Calculate()
	{
		T result = *DataArray[0];
		size_t i = 1;
		for (const std::string& action : Actions)
		{
			switch (action[0])
			{
			case '+':
				result += *DataArray[i];
				break;
			case '-':
				result -= *DataArray[i];
				break;
			case '*':
				result *= *DataArray[i];
				break;
			case '/':
				result /= *DataArray[i];
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

	//test foo
	void PrintActions()
	{
		std::cout << "Container's Actions are : \n";
		for (auto a : Actions)
			std::cout << a << " ";
		std::cout << "\n";
	}

private:

	void ReAllocation(size_t newCapacity)
	{

		std::unique_ptr<std::unique_ptr<T>[]> newBlock 
			= std::unique_ptr<std::unique_ptr<T>[]>(new std::unique_ptr<T>[newCapacity]);
		for (size_t i = 0; i < newCapacity; i++)
		{
			newBlock[i] = std::make_unique<T>();
		}


		if (newCapacity < Size)
			Size = newCapacity;

		for (size_t i = 0; i < Size; i++)
			*newBlock[i] = *DataArray[i];
		DataArray = std::move(newBlock);
		Capacity = newCapacity;
	}

};

