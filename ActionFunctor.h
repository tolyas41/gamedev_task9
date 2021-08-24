#pragma once
#include "Container.h"
#include <string>
#include <map>
#include <functional>

class ActionFunctor
{
	Matrix result;

	struct Functor
	{
		void operator()(char action, Matrix& result, const Container<Matrix>& container, int i) 
		{
			switch (action)
			{
			case '+':
				result += *container.DataArray[i + 1];
				break;
			case '-':
				result -= *container.DataArray[i + 1];
				break;
			case '*':
				result *= *container.DataArray[i + 1];
				break;
			case '/':
				result /= *container.DataArray[i + 1];
				break;
			default:
				std::cout << "\nERR: wrong symbols! acceptable only:\n+-/*\n";
				break;
			}
			i++;
		}
	};

	std::map <char, std::function<void(char action, Matrix& result, const Container<Matrix>& container, int i)>> ActionsMap;

public:

	ActionFunctor()
	{
		ActionsMap['+'] = Functor();
		ActionsMap['-'] = Functor();
		ActionsMap['*'] = Functor();
		ActionsMap['/'] = Functor();
	}

	Matrix Calculate_functor(const std::string& actions, const Container<Matrix>& container)
	{
		int i = 0;
		result = *container.DataArray[i];
		for (auto action : actions)
		{
			ActionsMap[action](action, result, container, i);
			i++;
		}
		return result;
	}
};
