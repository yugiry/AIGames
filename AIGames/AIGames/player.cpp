#pragma once
#include "player.h"

int SPEED = 4.0f;

CPlayer::CPlayer()
{
	ImgWidth = 32;
	ImgHeight = 32;

	pos.x = WINDOW_WIDTH / 2 - ImgWidth / 2;
	pos.y = WINDOW_HEIGHT / 2 - ImgHeight / 2;

	img = LoadGraph("image\\player.png");

	pri = 1;
}

CPlayer::CPlayer(Point p)
{
	pos = p;

	img = LoadGraph("image\\player.png");

	pri = 1;
}

int CPlayer::Action(vector<unique_ptr<BaseVector>>& base)
{
	vec.x = vec.y = 0;

	if (CheckHitKey(KEY_INPUT_W))vec.y = -SPEED;
	if (CheckHitKey(KEY_INPUT_S))vec.y = SPEED;
	if (CheckHitKey(KEY_INPUT_A))vec.x = -SPEED;
	if (CheckHitKey(KEY_INPUT_D))vec.x = SPEED;

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
}