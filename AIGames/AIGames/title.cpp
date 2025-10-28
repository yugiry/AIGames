#include "DxLib.h"
#include "Scene_Manager.h"
#include "title.h"
#include "game.h"
#include "function.h"

CTitle::CTitle(CManager* p) :CScene(p)
{

}

int CTitle::Update()
{

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		manager->Scene_Delete();
		manager->scene = new CGame(manager);
		WAIT_RELEASE_ALL_KEY();
	}

	return 0;
}

void CTitle::Draw()
{
	DrawString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, "ENTER : START", GetColor(255, 255, 255));
}

CTitle::~CTitle()
{

}