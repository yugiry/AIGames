#pragma once
#include "player.h"
#include "fonUI.h"
#include "function.h"

int SPEED = 4.0f;

CPlayer::CPlayer()
{
	ImgWidth = 32;
	ImgHeight = 32;

	pos.x = WINDOW_WIDTH / 2 - ImgWidth / 2;
	pos.y = WINDOW_HEIGHT / 2 - ImgHeight / 2;

	img = LoadGraph("image\\player.png");

	ID = PLAYER;

	pri = 2;
}

CPlayer::CPlayer(Point p)
{
	pos = p;

	img = LoadGraph("image\\player.png");

	ID = PLAYER;

	pri = 2;
}

int CPlayer::Action(vector<unique_ptr<BaseVector>>& base)
{
	vec.x = vec.y = 0;

	if (!open_UI)
	{
		if (CheckHitKey(KEY_INPUT_W))vec.y = -SPEED;
		if (CheckHitKey(KEY_INPUT_S))vec.y = SPEED;
		if (CheckHitKey(KEY_INPUT_A))vec.x = -SPEED;
		if (CheckHitKey(KEY_INPUT_D))vec.x = SPEED;
	}

	//画面スクロールの当たり判定
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->ID == WGROUND)
		{
			if (HitCheck_box(pos.x, pos.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
			{
				if (pos.x + vec.x < 0)
				{
					if (now_scene != 3)now_scene--;
					if (now_scene < 0)now_scene = 0;
					pos.x = WINDOW_WIDTH - ImgWidth * 2;
					return 1;
				}
				if (pos.x + vec.x > WINDOW_WIDTH - ImgWidth)
				{
					if (now_scene != 2)now_scene++;
					if (now_scene > 5)now_scene = 5;
					pos.x = ImgWidth;
					return 2;
				}
			}
		}
		if ((*i)->ID == USTAIR)
		{
			if (HitCheck_box(pos.x, pos.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
			{
				for (auto i = base.begin(); i != base.end(); i++)
				{
					if ((*i)->ID == DARK)
					{
						if (HitCheck_box(pos.x, pos.y + vec.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
						{
							if (now_scene == 0)pos.x = ImgWidth * 2; pos.y = 256;
							if (now_scene == 2)pos.x = WINDOW_WIDTH - ImgWidth * 2; pos.y = 256;
							now_scene += 3;
							return 3;
						}
					}
				}
			}
		}
		if ((*i)->ID == DSTAIR)
		{
			if (HitCheck_box(pos.x, pos.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
			{
				for (auto i = base.begin(); i != base.end(); i++)
				{
					if ((*i)->ID == DARK)
					{
						if (HitCheck_box(pos.x, pos.y + vec.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
						{
							if (now_scene == 0)pos.x = ImgWidth * 2; pos.y = 256;
							if (now_scene == 2)pos.x = WINDOW_WIDTH - ImgWidth * 2; pos.y = 256;
							now_scene -= 3;
							return 4;
						}
					}
				}
			}
		}
		if ((*i)->ID == FON)
		{
			if (HitCheck_box(pos.x - ImgWidth / 2, pos.y - ImgHeight / 2, (*i)->pos.x, (*i)->pos.y, ImgWidth * 2, ImgHeight * 2, (*i)->ImgWidth, (*i)->ImgHeight))
			{
				if (CheckHitKey(KEY_INPUT_F))
				{
					//黒電話UIの表示
					base.emplace_back((unique_ptr<BaseVector>)new CFonUI());
					open_UI = true;
				}
			}
		}
	}
	//当たり判定
	{
		//Ｘ軸の当たり判定
		{
			Point late{ pos.x + vec.x,pos.y };
			for (auto i = base.begin(); i != base.end(); i++)
			{
				if ((*i)->ID == WALL || (*i)->ID == DARK || (*i)->ID==FON)
				{

					if (HitCheck_box(late.x, late.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
					{
						vec.x = 0;
					}
				}
			}
		}
		//Ｙ軸の当たり判定
		{
			Point late{ pos.x,pos.y + vec.y };
			for (auto i = base.begin(); i != base.end(); i++)
			{
				if ((*i)->ID == WALL || (*i)->ID == DARK || (*i)->ID==FON)
				{

					if (HitCheck_box(late.x, late.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight, (*i)->ImgWidth, (*i)->ImgHeight))
					{
						vec.y = 0;
					}
				}
			}
		}
	}

	pos.x += vec.x;
	pos.y += vec.y;

	if (pos.x < 0)pos.x = 0;
	if (pos.x > WINDOW_WIDTH - ImgWidth)pos.x = WINDOW_WIDTH - ImgWidth;
	if (pos.y < 0)pos.y = 0;
	if (pos.y > WINDOW_HEIGHT - ImgHeight)pos.y = WINDOW_HEIGHT - ImgHeight;

	return 0;
}

void CPlayer::Draw()
{
	DrawGraph(pos.x, pos.y, img, true);

	DrawFormatString(0, 40, GetColor(255, 255, 255), "x=%f,y=%f", pos.x, pos.y);
}