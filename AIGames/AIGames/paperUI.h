#pragma once
#include "objBase.h"

class CPaperUI :public BaseVector
{
public:
	CPaperUI(int);

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	bool push_f{ true };
};