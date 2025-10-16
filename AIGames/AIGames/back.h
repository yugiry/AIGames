#pragma once
#include "objBase.h"

class CBack :public BaseVector
{
public:
	//座標、チップ番号、画像ハンドル
	CBack(Point, int, int);
	~CBack() {  };

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	int No{ -1 };
};