#include "back.h"

CBack::CBack(Point p, int _No, int _img)
{
	pos = p;

	ImgWidth = BLOCK_WIDTH;
	ImgHeight = BLOCK_HEIGHT;

	No = _No;
	img = _img;
	pri = 0;

	if (No == 0)
	{
		ID = DARK;
	}
	else if (No == 1)
	{
		ID = WGROUND;
	}
	else if (No == 2 || No == 3 || No == 6 || No == 7)
	{
		ID = WALL;
	}
	else if (No == 16)
	{
		ID = USTAIR;
	}
	else if (No == 17)
	{
		ID = DSTAIR;
	}
	else if (No == 18)
	{
		ID = FON;
		pri = 1;
	}
	else if (No == 21 || No == 24 || No == 25)
	{
		ID = DESKS;
		pri = 1;
	}
	else
	{
		ID = GROUND;
	}

	CutX = BLOCK_WIDTH * (No % 8);
	CutY = BLOCK_HEIGHT * (No / 8);
}

int CBack::Action(vector<unique_ptr<BaseVector>>& base)
{
	return 0;
}

void CBack::Draw()
{
	DrawRectGraph(pos.x, pos.y, CutX, CutY, ImgWidth, ImgHeight, img, true);
}