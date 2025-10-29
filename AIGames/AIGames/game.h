//ゲームシーンヘッダ
#pragma once
#include "objBase.h"
#include "CCamera.h"
#include "map.h"

class CGame :public CScene
{
private:
public:
	//オブジェクト
	//リスト
	//list<unique_ptr<Base3D>> base3D;//3Dオブジェクト
	//list<unique_ptr<Base>> base;//2Dオブジェクト
	//ベクター
	vector<unique_ptr<BaseVector>> base;

	//コンストラクタ
	CGame(CManager*);

	//デストラクタ
	~CGame();

	int Update();//更新処理
	void Draw();//描画処理

	int map_num{ 1 };

	CMap* map;

	bool clear{ false };
	bool clear_scene{ false };

	//CCamera* camera;//カメラオブジェクト
};