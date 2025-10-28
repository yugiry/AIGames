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
			map->MapCreation(base, map_num);
			break;
		case 2://右に画面を動かしたとき
			if (map_num != 2)map_num++;
			map->MapCreation(base, map_num);
			break;
		case 3://階段(上る)
			map_num += 3;
			map->MapCreation(base, map_num);
			break;
		case 4://階段(下る)
			map_num -= 3;
			map->MapCreation(base, map_num);
			break;
		case 7://教室１
			map_num = 8;
			map->MapCreation(base, map_num);
			break;
		case 8://教室２
			map_num = 9;
			map->MapCreation(base, map_num);
			break;
		case 9://教室から二階廊下左に
			map_num = 3;
			map->MapCreation(base, map_num);
			break;
		case 10://教室から二階廊下真ん中に
			map_num = 4;
			map->MapCreation(base, map_num);
			break;
		case 11://教室から二階廊下右に
			map_num = 5;
			map->MapCreation(base, map_num);
			break;
		case 5://左職員室
			map_num = 6;
			map->MapCreation(base, map_num);
			break;
		case 6://右職員室
			map_num = 7;
			map->MapCreation(base, map_num);
			break;
		case 12://左職員室から一階廊下左に
			map_num = 0;
			map->MapCreation(base, map_num);
			break;
		case 13://右職員室から一階廊下右に
			map_num = 2;
			map->MapCreation(base, map_num);
			break;
		case 20://ゲームクリア
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
}

CGame::~CGame()
{

}
