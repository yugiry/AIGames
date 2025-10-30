#pragma once
#include "fonUI.h"

CFonUI::CFonUI()
{
	img = LoadGraph("image\\fon.png");
	center = LoadGraph("image\\center.png");
	stopper = LoadGraph("image\\stopper.png");

	ImgWidth = 500;
	ImgHeight = 500;

	pos.x = WINDOW_WIDTH / 2 - ImgWidth / 2;
	pos.y = WINDOW_HEIGHT / 2 - ImgHeight / 2;

	pri = 5;
}

int CFonUI::Action(vector<unique_ptr<BaseVector>>& base)
{
	if (push_num)
	{
		if (!reverse)
		{
			if (radius <= rotato)
			{
				radius+=3;
			}
			if (radius >= rotato)reverse = true;
		}
		if (reverse)
		{
			if (radius > 0)
			{
				radius--;
			}
			if (radius == 0)
			{
				push_num = false;
				reverse = false;
			}
		}
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		dial.clear();
	}

	if (CheckHitKey(KEY_INPUT_F) && !push_f)
	{
		FLAG = false;
	}
	push_f = CheckHitKey(KEY_INPUT_F);
	if (!push_num && dial.size() < 3)
	{
		if (CheckHitKey(KEY_INPUT_1))
		{
			dial.push_back(ONE);
			push_num = true;
			rotato = 85;
		}
		if (CheckHitKey(KEY_INPUT_2))
		{
			dial.push_back(TWO);
			push_num = true;
			rotato = 110;
		}
		if (CheckHitKey(KEY_INPUT_3))
		{
			dial.push_back(THREE);
			push_num = true;
			rotato = 135;
		}
		if (CheckHitKey(KEY_INPUT_4))
		{
			dial.push_back(FOUR);
			push_num = true;
			rotato = 155;
		}
		if (CheckHitKey(KEY_INPUT_5))
		{
			dial.push_back(FIVE);
			push_num = true;
			rotato = 185;
		}
		if (CheckHitKey(KEY_INPUT_6))
		{
			dial.push_back(SIX);
			push_num = true;
			rotato = 210;
		}
		if (CheckHitKey(KEY_INPUT_7))
		{
			dial.push_back(SEVEN);
			push_num = true;
			rotato = 235;
		}
		if (CheckHitKey(KEY_INPUT_8))
		{
			dial.push_back(EIGHT);
			push_num = true;
			rotato = 265;
		}
		if (CheckHitKey(KEY_INPUT_9))
		{
			dial.push_back(NINE);
			push_num = true;
			rotato = 290;
		}
		if (CheckHitKey(KEY_INPUT_0))
		{
			dial.push_back(ZERO);
			push_num = true;
			rotato = 315;
		}
	}

	if (radius < 0)radius = 0;

	//•“d˜b‚ª“®‚¢‚Ä‚¢‚È‚¢Žž
	if (!push_num && !reverse && dial.size() == 3)
	{
		//“ü—Í‚³‚ê‚½‚R‚Â‚Ì”Ô†‚ª‚ ‚Á‚Ä‚¢‚é
		if (dial[0] == 1 && dial[1] == 2 && dial[2] == 5)
		{
			return 20;
		}
	}

	return 0;
}

void CFonUI::Draw()
{
	DrawGraph(pos.x, pos.y, img, true);

	DrawRotaGraph(pos.x + ImgWidth / 2, pos.y + ImgHeight / 2 + 60, 1, RADIAN(radius), center, true);

	DrawGraph(pos.x + ImgWidth / 2 + 30, pos.y + ImgHeight / 2 + 90, stopper, true);
}