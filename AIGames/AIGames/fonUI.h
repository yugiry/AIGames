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

	int center{ -1 };
	int stopper{ -1 };

	int rotato{ 0 };
	int radius{ 0 };

	bool push_f{ true };
	bool push_num{ false };
	bool push_enter{ false };
	bool reverse{ false };
	bool wrongsound{ false };

	vector<int> dial;
};