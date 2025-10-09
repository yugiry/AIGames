#pragma once
#include "objBase.h"

class CMap
{
public:
	CMap();
	~CMap();

	void LoadMap();

	void MapCreation(vector<unique_ptr<BaseVector>>&);

	int img{ -1 };

	int map[MAP_WIDTH * MAP_HEIGHT];
};