#pragma once
#include "objBase.h"

class CPlayer :public BaseVector
{
public:
	CPlayer();
	CPlayer(Point);

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	int now_scene{ 1 };

	bool open_UI{ false };
	bool push_f{ false };
};