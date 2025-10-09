#pragma once
#include "objBase.h"

class CPlayer :public BaseVector
{
public:
	CPlayer();
	CPlayer(Point);

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();
};