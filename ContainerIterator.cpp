#include "ContainerIterator.h"


ContainerIterator::ContainerIterator(Matrix* obj_ptr)
	: it_Ptr(obj_ptr) {}

ContainerIterator& ContainerIterator::operator++()
{
	it_Ptr++;
	return *this;
}

ContainerIterator& ContainerIterator::operator++(int)
{
	ContainerIterator iterator = *this;
	++(*this);
	return iterator;
}

ContainerIterator& ContainerIterator::operator--()
{
	it_Ptr--;
	return *this;
}

ContainerIterator& ContainerIterator::operator--(int)
{
	ContainerIterator iterator = *this;
	--(*this);
	return iterator;
}

Matrix& ContainerIterator::operator[](size_t index)
{
	return *(it_Ptr + index);
}

Matrix* ContainerIterator::operator->()
{
	return it_Ptr;
}

Matrix& ContainerIterator::operator*()
{
	return *it_Ptr;
}

bool ContainerIterator::operator==(const ContainerIterator& other) const
{
	return it_Ptr == other.it_Ptr;
}

bool ContainerIterator::operator!=(const ContainerIterator& other) const
{
	return !(*this == other);
}

Matrix& ContainerIterator::first()
{
	return it_Ptr[0];
}

void ContainerIterator::next()
{
	it_Ptr++;
}
