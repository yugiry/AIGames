#pragma once
#include "paperUI.h"

CPaperUI::CPaperUI(int num)
{
	ImgWidth = 500;
	ImgHeight = 500;

	pos.x = WINDOW_WIDTH / 2 - ImgWidth / 2;
	pos.y = WINDOW_HEIGHT / 2 - ImgHeight / 2;

	if (num == 0)
	{
		img = LoadGraph("image\\papers2.png");
	}
	if (num == 1)
	{
		img = LoadGraph("image\\papers5.png");
	}
	if (num == 2)
	{
		img = LoadGraph("image\\papers1.png");
	}

	pri = 5;
}

int CPaperUI::Action(vector<unique_ptr<BaseVector>>& base)
{
	if (CheckHitKey(KEY_INPUT_F) && !push_f)
	{
		FLAG = false;
	}
	push_f = CheckHitKey(KEY_INPUT_F);

	return 0;
}

void CPaperUI::Draw()
{
	DrawGraph(pos.x, pos.y, img, true);
}