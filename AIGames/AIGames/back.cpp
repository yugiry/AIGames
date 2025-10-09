#include "back.h"

CBack::CBack(Point p, int _No, int _img, int _ID)
{
	pos = p;

	ImgWidth = BLOCK_WIDTH;
	ImgHeight = BLOCK_HEIGHT;

	No = _No;
	img = _img;
	ID = _ID;

	if (No == 1)
	{
		CutX = BLOCK_WIDTH;
		CutY = 0;
	}
	if (No == 2)
	{
		CutX = BLOCK_WIDTH * 2;
		CutY = 0;
	}

	pri = 0;
}

int CBack::Action(vector<unique_ptr<BaseVector>>& base)
{
	return 0;
}

void CBack::Draw()
{
	DrawRectGraph(pos.x, pos.y, CutX, CutY, ImgWidth, ImgHeight, img, true);
}