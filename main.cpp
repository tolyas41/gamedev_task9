#include "Matrix.h"
#include <vector>
#include <iostream>
#include <memory>

#include "Container.h"
#include "ActionFunctor.h"

int main() {

	Matrix obj0(9, 3, 3);
	Matrix obj1(4, 3, 3);
	Matrix obj2(1, 3, 3);
	Matrix obj3(3, 3, 3);
	Matrix obj4(4, 3, 3);
	Matrix obj5(5, 3, 3);

	Container<Matrix> mat1;

	mat1.PushBack(obj0);
	mat1.PushBack(obj1);
	mat1.PushBack(obj2);
	mat1.PushBack(obj3);
	mat1.PushBack(obj4);
	mat1.PushBack(obj5);
	mat1.PrintMatrices();


	mat1.LoadAction();
	mat1.PrintActions();
	mat1.Calculate().print_array();

	ActionFunctor action;
	std::string actions = "+-*";
	std::cout << "action functor's result with " << actions << " is : \n";
	action(actions, mat1).print_array();


	return 0;
}

