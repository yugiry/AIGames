#pragma once
#include "player.h"
#include "fonUI.h"
#include "paperUI.h"
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

	pri = 4;
}

CPlayer::CPlayer(Point p)
{
	pos = p;

	img = LoadGraph("image\\player.png");

	ID = PLAYER;

	pri = 4;
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
	else
	{
		if (CheckHitKey(KEY_INPUT_F) && !push_f)
		{
			open_UI = false;
			push_f = true;
		}
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
					pos.x = WINDOW_WIDTH - ImgWidth * 2;
					return 1;
				}
				if (pos.x + vec.x > WINDOW_WIDTH - ImgWidth)
				{
					if (now_scene != 2)now_scene++;
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
				if (CheckHitKey(KEY_INPUT_F) && !push_f)
				{
					//黒電話UIの表示
					base.emplace_back((unique_ptr<BaseVector>)new CFonUI());
					open_UI = true;
				}
				push_f = CheckHitKey(KEY_INPUT_F);
			}
		}
		if ((*i)->ID == PAPER)
		{
			if (HitCheck_box(pos.x - ImgWidth / 2, pos.y - ImgHeight / 2, (*i)->pos.x, (*i)->pos.y, ImgWidth * 2, ImgHeight * 2, (*i)->ImgWidth, (*i)->ImgHeight))
			{
				if (CheckHitKey(KEY_INPUT_F) && !push_f)
				{
					if (now_scene == 7)
					{
						base.emplace_back((unique_ptr<BaseVector>)new CPaperUI(0));
					}
					if (now_scene == 8)
					{
						base.emplace_back((unique_ptr<BaseVector>)new CPaperUI(1));
					}
					if (now_scene == 9)
					{
						base.emplace_back((unique_ptr<BaseVector>)new CPaperUI(2));
					}
					open_UI = true;
				}
				push_f = CheckHitKey(KEY_INPUT_F);
			}
		}
		if ((*i)->ID == DOOR)
		{
			if (HitCheck_box(pos.x + vec.x, pos.y + vec.y, (*i)->pos.x, (*i)->pos.y, ImgWidth, ImgHeight))
			{
				if ((*i)->vec.x == 1)
				{
					if ((*i)->vec.y == 1) { pos.x = 192; pos.y = 448; now_scene = 6; return 5; }
					if ((*i)->vec.y == 2) { pos.x = 448; pos.y = 256; now_scene = 0; return 12; }
				}
				if ((*i)->vec.x == 2)
				{
					if ((*i)->vec.y == 1) { pos.x = 448; pos.y = 448; now_scene = 7; return 6; }
					if ((*i)->vec.y == 2) { pos.x = 192; pos.y = 256; now_scene = 2; return 13; }
				}
				if ((*i)->vec.x == 3)
				{
					if ((*i)->vec.y == 1) { pos.x = 96; pos.y = 384; }
					if ((*i)->vec.y == 2) { pos.x = 544; pos.y = 384; }
					now_scene = 8;
					return 7;
				}
				if ((*i)->vec.x == 4)
				{
					if ((*i)->vec.y == 1) { pos.x = 96; pos.y = 384; }
					if ((*i)->vec.y == 2) { pos.x = 544; pos.y = 384; }
					now_scene = 9;
					return 8;
				}
				if ((*i)->vec.x == 5)
				{
					if ((*i)->vec.y == 1) { pos.x = 192; pos.y = 256; now_scene = 3; return 9; }
					if ((*i)->vec.y == 2) { pos.x = 256; pos.y = 256; now_scene = 4; return 10; }
				}
				if ((*i)->vec.x == 6)
				{
					if ((*i)->vec.y == 1) { pos.x = 416; pos.y = 256; now_scene = 4; return 10; }
					if ((*i)->vec.y == 2) { pos.x = 448; pos.y = 256; now_scene = 5; return 11; }
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
				if ((*i)->ID == WALL || (*i)->ID == DARK || (*i)->ID == FON || (*i)->ID == DOOR || (*i)->ID == DESKS || (*i)->ID == PAPER)
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
				if ((*i)->ID == WALL || (*i)->ID == DARK || (*i)->ID == FON || (*i)->ID == DOOR || (*i)->ID == DESKS || (*i)->ID == PAPER)
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
	if (pos.y > WINDOW_HEIGHT - ImgHeight)
	{
		pos.y = WINDOW_HEIGHT - ImgHeight;
		return 19;
	}

	return 0;
}

void CPlayer::Draw()
{
	DrawGraph(pos.x, pos.y, img, true);
}