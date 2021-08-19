#pragma once
#include <string>
#include "Matrix.h"
#include "Container.h"


class ActionFunctor
{
	//Create a class that stores map in itself for
	//converting “action” lines into a functor for implementing this action.
public:

	Matrix operator()(std::string actions, const Container<Matrix>& container) 
	{
		Matrix result = container.DataPtr[0];
		for (size_t i = 0; i < actions.size(); i++)
		{
			switch (actions[i])
			{
			case '+':
				result += container.DataPtr[i + 1];
				break;
			case '-':
				result -= container.DataPtr[i + 1];
				break;
			case '*':
				result *= container.DataPtr[i + 1];
				break;
			case '/':
				result /= container.DataPtr[i + 1];
				break;
			default:
				std::cout << "\nERR: wrong symbols! acceptable only:\n+-/*\n";
				return result;
			}
			if (i > container.Size)
			{
				return result;
			}
		}
		return result;
	}
};
