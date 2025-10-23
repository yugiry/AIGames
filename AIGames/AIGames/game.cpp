//ゲームシーン
#include "DxLib.h"
#include "Scene_Manager.h"
#include "game.h"
#include "function.h"

#include "player.h"

//コンストラクタ
CGame::CGame(CManager* p) :CScene(p){
	map = new CMap();

	map->LoadMap();
	map->MapCreation(base, map_num);

	base.emplace_back((unique_ptr<BaseVector>)new CPlayer());
}

//更新処理
int CGame::Update(){
	//更新処理
	for (int i = 0; i < base.size(); i++)
		switch (base[i]->Action(base))
		{
		case 1://左に画面を動かしたとき
			if (map_num != 3)map_num--;
			if (map_num < 0)map_num = 0;
			map->MapCreation(base, map_num);
			break;
		case 2://右に画面を動かしたとき
			if (map_num != 2)map_num++;
			if (map_num > 5)map_num = 5;
			map->MapCreation(base, map_num);
			break;
		case 3:
			map_num += 3;
			map->MapCreation(base, map_num);
			break;
		case 4:
			map_num -= 3;
			map->MapCreation(base, map_num);
			break;
		}

	//削除処理
	for (auto i = base.begin(); i != base.end();)
		(*i)->FLAG ? i++ : i = base.erase(i);

	//オブジェクトのソート処理(クイックソート)
	ObjSort_Quick(base, 0, base.size() - 1);

	//listオブジェクトの更新処理	
	//for (auto i = base.begin(); i != base.end(); i++)
	//	(*i)->Action(base);

	return 0;
}

//描画処理
void CGame::Draw()
{	
	for (int i = 0; i < base.size(); i++)
		if(base[i]->FLAG) base[i]->Draw();

	//オブジェクト個数
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Object_Count = %d", base.size());

	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", map_num);
}

CGame::~CGame()
{

}
