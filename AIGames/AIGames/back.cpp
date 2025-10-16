#include "back.h"

CBack::CBack(Point p, int _No, int _img)
{
	pos = p;

	ImgWidth = BLOCK_WIDTH;
	ImgHeight = BLOCK_HEIGHT;

	No = _No;
	img = _img;

	if (No == 2 || No == 6 || No == 7)
	{
		ID = WALL;
	}
	else
	{
		ID = GROUND;
	}

	CutX = BLOCK_WIDTH * (No % 8);
	CutY = BLOCK_HEIGHT * (No / 8);


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