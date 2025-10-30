#pragma once
#include "paper.h"

CPaper::CPaper(Point p)
{
	img = LoadGraph("image\\paper.png");

	pos = p;

	ImgWidth = BLOCK_WIDTH;
	ImgHeight = BLOCK_HEIGHT;

	ID = PAPER;
	pri = 3;
}

int CPaper::Action(vector<unique_ptr<BaseVector>>& base)
{
	return 0;
}

void CPaper::Draw()
{
	DrawGraph(pos.x, pos.y, img, true);
}