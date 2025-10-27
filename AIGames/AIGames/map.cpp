#pragma once
#include "map.h"

#include "back.h"
#include "door.h"

#include <fstream>
#include <sstream>

CMap::CMap()
{
	img = LoadGraph("image\\map_img.png");
}

void CMap::LoadMap()
{
	int i, j, k;
	//�f�[�^���[�h
	ifstream fromFile("map\\fmap.txt");
	//�t�@�C�������邩�ǂ����`�F�b�N
	if (!fromFile)
		return;

	string data;
	std::istringstream ss;
	i = 0;
	j = 0;
	//�t�@�C���̏I���܂ŉ�
	while (fromFile.eof() == false)
	{
		j = 0;
		//�t�@�C�������s�����data�Ɋi�[
		getline(fromFile, data);
		data.insert(data.size(), ",");//�s�̒[����","������
		//�s�̍ŏ���'#'�Ȃ�
		if (data[0] == '#')
		{
			char num = data[1];
			k = num - '0';
			i = 0;
		}
		else
		{
			//�擾�����s���琔�����擾
			while (data.size())
			{
				//�Z����","�܂ł̕�������T��
				int num_end = data.find(",");
				string num_str = data.substr(0, num_end);//�������擾
				//�����𐔒l�ɂ���map�ɓ����
				ss = istringstream(num_str);
				ss >> map[k][j + i * MAP_WIDTH];
				//"����,"�܂ł��폜
				data = data.erase(0, num_end + 1);
				j++;
			}
			i++;
		}
	}
}

void CMap::MapCreation(vector<unique_ptr<BaseVector>>& base, int map_num)
{
	img = LoadGraph("image\\map_img.png");

	for(auto i = base.begin();i!=base.end();i++)
		if ((*i)->ID != PLAYER)
		{
			(*i)->FLAG = false; (*i)->ID = -1;
		}

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			Point p{ x * BLOCK_WIDTH,y * BLOCK_HEIGHT };
			if (map[map_num][x + y * MAP_WIDTH] == 11 || map[map_num][x + y * MAP_WIDTH] == 12)
			{
				base.emplace_back((unique_ptr<BaseVector>)new CDoor(p, map[map_num][x + y * MAP_WIDTH], map_num));
			}
			else if (map[map_num][x + y * MAP_WIDTH] == 25 || map[map_num][x + y * MAP_WIDTH] == 21)
			{
				base.emplace_back((unique_ptr<BaseVector>)new CBack(p, 20, img));
				base.emplace_back((unique_ptr<BaseVector>)new CBack(p, map[map_num][x + y * MAP_WIDTH], img));
			}
			else if (map[map_num][x + y * MAP_WIDTH] == 24)
			{
				base.emplace_back((unique_ptr<BaseVector>)new CBack(p, 19, img));
				base.emplace_back((unique_ptr<BaseVector>)new CBack(p, map[map_num][x + y * MAP_WIDTH], img));
			}
			else
			{
				if (map[map_num][x + y * MAP_WIDTH] == 18 || map[map_num][x + y * MAP_WIDTH] == 26 || map[map_num][x + y * MAP_WIDTH] == 27)
					base.emplace_back((unique_ptr<BaseVector>)new CBack(p, 1, img));
				base.emplace_back((unique_ptr<BaseVector>)new CBack(p, map[map_num][x + y * MAP_WIDTH], img));
			}
		}
	}
}

CMap::~CMap()
{
	
}