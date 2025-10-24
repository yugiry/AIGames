#pragma once
#include "objBase.h"

class CFonUI :public BaseVector
{
public:
	CFonUI();

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	bool push_f{ true };
};