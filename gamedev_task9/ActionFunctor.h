#pragma once
#include "Container.h"
#include <string>
#include <map>
#include <functional>

class ActionFunctor
{
	//Create a class that stores map in itself for
	//converting “action” lines into a functor for implementing this action.

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

	typedef std::function<void(char action, Matrix& result, const Container<Matrix>& container, int i)> ActionFunction;

	std::map <char, ActionFunction> ActionsMap;
	std::map <char, ActionFunction>::iterator it = ActionsMap.begin();

public:

	ActionFunctor()
	{
		ActionFunction func = Functor();
		ActionsMap['+'] = func;
		ActionsMap['-'] = func;
		ActionsMap['*'] = func;
		ActionsMap['/'] = func;
	}

	Matrix Calculate_functor(const std::string& actions, const Container<Matrix>& container)
	{
		int i = 0;
		result = *container.DataArray[0];
		for (const auto& action : actions)
		{
			ActionsMap[action](action, result, container, i);
			i++;
		}
		return result;
	}
};
