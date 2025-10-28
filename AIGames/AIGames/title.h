#pragma once
#include "objBase.h"

class CTitle :public CScene
{
public:
	list<unique_ptr<BaseVector>> base;

	CTitle(CManager*);

	~CTitle();

	int Update();
	void Draw();
};