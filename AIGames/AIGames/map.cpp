#pragma once
#include "map.h"

#include "back.h"

#include <fstream>
#include <sstream>

CMap::CMap()
{
	img = LoadGraph("image\\map_img.png");
}

void CMap::LoadMap()
{
	int i, j, k;
	//データロード
	ifstream fromFile("map\\fmap.txt");
	//ファイルがあるかどうかチェック
	if (!fromFile)
		return;

	string data;
	std::istringstream ss;
	i = 0;
	j = 0;
	//ファイルの終わりまで回す
	while (fromFile.eof() == false)
	{
		j = 0;
		//ファイルから一行分列のdataに格納
		getline(fromFile, data);
		data.insert(data.size(), ",");//行の端末に","をつける
		//行の最初が'#'なら
		if (data[0] == '#')
		{
			char num = data[1];
			k = num - '0';
			i = 0;
		}
		else
		{
			//取得した行から数字を取得
			while (data.size())
			{
				//セルの","までの文字数を探す
				int num_end = data.find(",");
				string num_str = data.substr(0, num_end);//数字を取得
				//数字を数値にしてmapに入れる
				ss = istringstream(num_str);
				ss >> map[k][j + i * MAP_WIDTH];
				//"数字,"までを削除
				data = data.erase(0, num_end + 1);
				j++;
			}
			i++;
		}
	}
}

void CMap::MapCreation(vector<unique_ptr<BaseVector>>& base, int map_num)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			Point p{ x * BLOCK_WIDTH,y * BLOCK_HEIGHT };
			base.emplace_back((unique_ptr<BaseVector>)new CBack(p, map[map_num][x + y * MAP_WIDTH], img));
		}
	}
}

CMap::~CMap()
{
	
}