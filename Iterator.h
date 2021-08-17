#pragma once
#include "Matrix.h"

class Iterator {

public:
	virtual Matrix& first() = 0;
	virtual void next() = 0;
};

