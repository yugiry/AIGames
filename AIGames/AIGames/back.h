#pragma once
#include "objBase.h"

class CBack :public BaseVector
{
public:
	//���W�A�`�b�v�ԍ��A�摜�n���h��
	CBack(Point, int, int);
	~CBack() {  };

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	int No{ -1 };
};