//�Q�[���V�[���w�b�_
#pragma once
#include "objBase.h"
#include "CCamera.h"
#include "map.h"

class CGame :public CScene
{
private:
public:
	//�I�u�W�F�N�g
	//���X�g
	//list<unique_ptr<Base3D>> base3D;//3D�I�u�W�F�N�g
	//list<unique_ptr<Base>> base;//2D�I�u�W�F�N�g
	//�x�N�^�[
	vector<unique_ptr<BaseVector>> base;

	//�R���X�g���N�^
	CGame(CManager*);

	//�f�X�g���N�^
	~CGame();

	int Update();//�X�V����
	void Draw();//�`�揈��

	int map_num{ 1 };

	CMap* map;

	bool clear{ false };
	bool clear_scene{ false };

	//CCamera* camera;//�J�����I�u�W�F�N�g
};