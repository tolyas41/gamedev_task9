#pragma once
#include "Matrix.h"
#include "Iterator.h"

class ContainerIterator: public Iterator
{
public:

	ContainerIterator(Matrix* obj_ptr);

	ContainerIterator& operator++();

	ContainerIterator& operator++(int);

	ContainerIterator& operator--();

	ContainerIterator& operator--(int);

	Matrix& operator[](size_t index);

	Matrix* operator->();

	Matrix& operator*();

	bool operator==(const ContainerIterator& other) const;

	bool operator!=(const ContainerIterator& other) const;

	virtual Matrix& first() override;

	virtual void next() override;

private:
	Matrix* it_Ptr;
};

