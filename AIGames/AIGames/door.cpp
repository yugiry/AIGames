#pragma once
#include "door.h"

CDoor::CDoor(Point p, int _No, int _map_num)
{
	img = LoadGraph("image\\door.png");

	pos = p;

	if (_No == 11)
		left = true;
	else if (_No == 12)
		left = false;

	if ((pos.x == 416 && _No == 11) || (pos.x == 448 && _No == 12)) { vec.x = 1; vec.y = 1; }
	if (_map_num == 6)
		if (true) {}
	if ((pos.x == 192 && _No == 11) || (pos.x == 224 && _No == 12)) { vec.x = 2; vec.y = 1; }
	if (_map_num == 7)
		if (true) {}
	if ((pos.x == 160 && _No == 11) || (pos.x == 192 && _No == 12)) { vec.x = 3; vec.y = 1; }
	if ((pos.x == 256 && _No == 11) || (pos.x == 288 && _No == 12)) { vec.x = 3; vec.y = 2; }
	if ((pos.x == 384 && _No == 11) || (pos.x == 416 && _No == 12)) { vec.x = 4; vec.y = 1; }
	if ((pos.x == 448 && _No == 11) || (pos.x == 480 && _No == 12)) { vec.x = 4; vec.y = 2; }

	if (_map_num == 8)
	{
		if ((pos.x == 64 && _No == 11) || (pos.x == 96 && _No == 12)) { vec.x = 5; vec.y = 1; }
		if ((pos.x == 544 && _No == 11) || (pos.x == 576 && _No == 12)) { vec.x = 5; vec.y = 2; }
	}
	else if (_map_num == 9)
	{
		if ((pos.x == 64 && _No == 11) || (pos.x == 96 && _No == 12)) { vec.x = 6; vec.y = 1; }
		if ((pos.x == 544 && _No == 11) || (pos.x == 576 && _No == 12)) { vec.x = 6; vec.y = 2; }
	}

	ImgWidth = BLOCK_WIDTH;
	ImgHeight = BLOCK_HEIGHT;

	ID = DOOR;
}

int CDoor::Action(vector<unique_ptr<BaseVector>>& base)
{
	return 0;
}

void CDoor::Draw()
{
	if (left)
		DrawRectGraph(pos.x, pos.y, 0, 0, ImgWidth, ImgHeight, img, true, false);
	else
		DrawRectGraph(pos.x, pos.y, 0, 0, ImgWidth, ImgHeight, img, true, true);

	DrawFormatString(pos.x, pos.y, GetColor(0, 255, 0), "%f\n%f", pos.x, pos.y);
}