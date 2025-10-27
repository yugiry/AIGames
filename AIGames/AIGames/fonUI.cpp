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
	if (CheckHitKey(KEY_INPUT_F) && !push_f)
	{
		FLAG = false;
	}
	push_f = CheckHitKey(KEY_INPUT_F);

	if (rotato == 0)
	{
		for (int i = 0; i < NUM_END; i++)
		{
			if (push_num[i])
			{
				rotato = EMPTY_ROTATO + ROTATO_TIME * i;
			}
		}
	}

	if (CheckHitKey(KEY_INPUT_1) && !push_num[ONE])
	{
		dial.push_back(ONE);
		push_num[ONE] = true;
	}
	if (CheckHitKey(KEY_INPUT_2) && !push_num[TWO])
	{
		dial.push_back(TWO);
		push_num[TWO] = true;
	}
	if (CheckHitKey(KEY_INPUT_3) && !push_num[THREE])
	{
		dial.push_back(THREE);
		push_num[THREE] = true;
	}
	if (CheckHitKey(KEY_INPUT_4) && !push_num[FOUR])
	{
		dial.push_back(FOUR);
		push_num[FOUR] = true;
	}
	if (CheckHitKey(KEY_INPUT_5) && !push_num[FIVE])
	{
		dial.push_back(FIVE);
		push_num[FIVE] = true;
	}
	if (CheckHitKey(KEY_INPUT_6) && !push_num[SIX])
	{
		dial.push_back(SIX);
		push_num[SIX] = true;
	}
	if (CheckHitKey(KEY_INPUT_7) && !push_num[SEVEN])
	{
		dial.push_back(SEVEN);
		push_num[SEVEN] = true;
	}
	if (CheckHitKey(KEY_INPUT_8) && !push_num[EIGHT])
	{
		dial.push_back(EIGHT);
		push_num[EIGHT] = true;
	}
	if (CheckHitKey(KEY_INPUT_9) && !push_num[NINE])
	{
		dial.push_back(NINE);
		push_num[NINE] = true;
	}
	if (CheckHitKey(KEY_INPUT_0) && !push_num[ZERO])
	{
		dial.push_back(ZERO);
		push_num[ZERO] = true;
	}


	return 0;
}

void CFonUI::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + ImgWidth, pos.y + ImgHeight, GetColor(0, 255, 0), true);
}