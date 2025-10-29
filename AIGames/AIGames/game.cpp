//�Q�[���V�[��
#include "DxLib.h"
#include "Scene_Manager.h"
#include "game.h"
#include "title.h"
#include "function.h"

#include "player.h"

//�R���X�g���N�^
CGame::CGame(CManager* p) :CScene(p){
	map = new CMap();

	map->LoadMap();
	map->MapCreation(base, map_num);

	base.emplace_back((unique_ptr<BaseVector>)new CPlayer());
}

//�X�V����
int CGame::Update(){
	//�X�V����
	for (int i = 0; i < base.size(); i++)
		switch (base[i]->Action(base))
		{
		case 1://���ɉ�ʂ𓮂������Ƃ�
			if (map_num != 3)map_num--;
			map->MapCreation(base, map_num);
			break;
		case 2://�E�ɉ�ʂ𓮂������Ƃ�
			if (map_num != 2)map_num++;
			map->MapCreation(base, map_num);
			break;
		case 3://�K�i(���)
			map_num += 3;
			map->MapCreation(base, map_num);
			break;
		case 4://�K�i(����)
			map_num -= 3;
			map->MapCreation(base, map_num);
			break;
		case 7://�����P
			map_num = 8;
			map->MapCreation(base, map_num);
			break;
		case 8://�����Q
			map_num = 9;
			map->MapCreation(base, map_num);
			break;
		case 9://���������K�L������
			map_num = 3;
			map->MapCreation(base, map_num);
			break;
		case 10://���������K�L���^�񒆂�
			map_num = 4;
			map->MapCreation(base, map_num);
			break;
		case 11://���������K�L���E��
			map_num = 5;
			map->MapCreation(base, map_num);
			break;
		case 5://���E����
			map_num = 6;
			map->MapCreation(base, map_num);
			break;
		case 6://�E�E����
			map_num = 7;
			map->MapCreation(base, map_num);
			break;
		case 12://���E���������K�L������
			map_num = 0;
			map->MapCreation(base, map_num);
			break;
		case 13://�E�E���������K�L���E��
			map_num = 2;
			map->MapCreation(base, map_num);
			break;
		case 19://�Q�[���N���A
			if (clear)
				clear_scene = true;
			break;
		case 20://���N���A
			clear = true;
			break;
		}

	//�폜����
	for (auto i = base.begin(); i != base.end();)
		(*i)->FLAG ? i++ : i = base.erase(i);

	//�I�u�W�F�N�g�̃\�[�g����(�N�C�b�N�\�[�g)
	ObjSort_Quick(base, 0, base.size() - 1);

	if (clear_scene)
	{
		manager->Scene_Delete();
		manager->scene = new CTitle(manager);
	}

	return 0;
}

//�`�揈��
void CGame::Draw()
{	
	for (int i = 0; i < base.size(); i++)
		if(base[i]->FLAG) base[i]->Draw();
}

CGame::~CGame()
{

}
