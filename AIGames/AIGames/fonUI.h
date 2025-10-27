#pragma once
#include "objBase.h"

constexpr int EMPTY_ROTATO{ 100 };
constexpr int ROTATO_TIME{ 0 };

class CFonUI :public BaseVector
{
public:
	CFonUI();

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	enum NUM
	{
		ZERO,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		NUM_END
	};

	int rotato{ 0 };

	bool push_f{ true };
	bool push_num[NUM_END]{ false };

	vector<int> dial;
};