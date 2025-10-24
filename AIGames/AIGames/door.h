#pragma once
#include "objBase.h"

class CDoor :public BaseVector
{
public:
	CDoor(Point, int, int);

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	bool left{ true };
};