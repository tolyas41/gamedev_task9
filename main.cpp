#include "Matrix.h"
#include <vector>
#include <iostream>
#include "Container.h"


int main() {


	Matrix obj0(5, 3, 3);
	Matrix obj1(1, 2, 2);
	Matrix obj2(2, 4, 4);
	Matrix obj3(3, 3, 3);
	Matrix obj4(4, 3, 3);
	Matrix obj5(5, 3, 3);

	Container mat1;

	mat1.PushBack(obj0);
	mat1.PushBack(obj1);
	mat1.PushBack(obj2);
	mat1.PushBack(Matrix(33, 2, 2));

	mat1.EmplaceBack(2, 3, 2);

	//mat1.PrintMatrices();
	//mat1.PopBack();
	//mat1.PopBack();
	//mat1.PrintMatrices();


	mat1.SortMatrices();

	for (Container::Iterator it = mat1.begin();
		it != mat1.end(); it.next())
	{
		it->print_array();
	}



	return 0;
}

