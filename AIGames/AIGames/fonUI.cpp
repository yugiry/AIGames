#pragma once
#include "fonUI.h"

CFonUI::CFonUI()
{
	ImgWidth = 500;
	ImgHeight = 500;

	pos.x = WINDOW_WIDTH / 2 - ImgWidth / 2;
	pos.y = WINDOW_HEIGHT / 2 - ImgHeight / 2;

	pri = 3;
}

int CFonUI::Action(vector<unique_ptr<BaseVector>>& base)
{
	return 0;
}

void CFonUI::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + ImgWidth, pos.y + ImgHeight, GetColor(0, 255, 0), true);
}