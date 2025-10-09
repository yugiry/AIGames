#pragma once
#include "objBase.h"

class CBack :public BaseVector
{
public:
	//座標、チップ番号、画像ハンドル、ID
	CBack(Point, int, int, int);
	~CBack() {  };

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	int No{ -1 };
};