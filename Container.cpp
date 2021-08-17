#include "Container.h"
#include "Matrix.h"

Container::Container()
{
	ReAllocation(2);
}

Container::~Container()
{
	Clear();
	::operator delete(MatrixObj, Capacity * sizeof(Matrix));
}

void Container::PushBack(const Matrix& obj)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	MatrixObj[Size] = obj;
	Size++;
}

void Container::PushBack(Matrix&& obj)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	MatrixObj[Size] = std::move(obj);
	Size++;
}

void Container::PopBack()
{
	if (Size > 0)
	{
		Size--;
		MatrixObj[Size].~Matrix();
	}
}

void Container::Clear()
{
	for (size_t i = 0; i < Size; i++)
		MatrixObj[i].~Matrix();

	Size = 0;
}

Matrix& Container::EmplaceBack(int data, size_t rows, size_t columns)
{
	if (Size >= Capacity)
		ReAllocation(Capacity + Capacity / 2);

	MatrixObj[Size] = Matrix(data, rows, columns);
	return MatrixObj[Size++];
}

size_t Container::GetSize() const
{
	return Size;
}


void Container::SortMatrices()
{
	bool IsSorted = false;
	while (!IsSorted) 
	{
		IsSorted = true;
		for (size_t i = 0; i < this->GetSize() - 1; i++) 
		{
			if (MatrixObj[i].DiagonalsProduct() > MatrixObj[i + 1].DiagonalsProduct()) 
			{
				Matrix temp;
				temp = MatrixObj[i];
				MatrixObj[i] = MatrixObj[i + 1];
				MatrixObj[i + 1] = temp;
				IsSorted = false;
			}
		}
	}
}

void Container::DeleteMatrix(size_t index) 
{
	if (index >= 0 && index < Size)
	{
		for (size_t i = 1; i < (Size - index); i++)
			MatrixObj[index + i - 1] = MatrixObj[index + i];
		MatrixObj[Size - 1].~Matrix();
		Size--;
	}
}

Matrix& Container::operator[] (size_t index)
{
	return MatrixObj[index];
}

void Container::PrintMatrices() 
{
	for (size_t i = 0; i < Size; i++) 
	{
		MatrixObj[i].print_array();
	}
}

void Container::ReAllocation(size_t newCapacity)
{
	Matrix* newBlock = (Matrix*)::operator new(newCapacity * sizeof(Matrix));

	if (newCapacity < Size)
		Size = newCapacity;

	for (size_t i = 0; i < Size; i++)
		new (&newBlock[i]) Matrix(std::move(MatrixObj[i]));

	for (size_t i = 0; i < Size; i++)
		MatrixObj[i].~Matrix();

	::operator delete(MatrixObj, Capacity * sizeof(Matrix));
	MatrixObj = newBlock;
	Capacity = newCapacity;
}