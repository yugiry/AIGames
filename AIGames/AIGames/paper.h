#pragma once
#include "objBase.h"

class CPaper :public BaseVector
{
public:
	CPaper(Point);

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();
};