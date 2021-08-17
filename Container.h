#pragma once
#include "ContainerIterator.h"


class Container
{

	Matrix* MatrixObj = nullptr;
	size_t Size = 0;
	size_t Capacity = 0;

public:

	using Iterator = ContainerIterator;

	Container();

	~Container();

	void PushBack(const Matrix& obj);

	void PushBack(Matrix&& obj);

	void PopBack();

	void Clear();

	Matrix& EmplaceBack(int data, size_t rows, size_t columns);

	size_t GetSize() const;

	Iterator begin()
	{
		return Iterator(MatrixObj);
	}

	Iterator end()
	{
		return Iterator(MatrixObj + Size);
	}

	void SortMatrices();

	void DeleteMatrix(size_t index);

	Matrix& operator[] (size_t index);

	void PrintMatrices();

private:
	void ReAllocation(size_t newCapacity);

};

