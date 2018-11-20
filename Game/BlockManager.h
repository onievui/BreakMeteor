#pragma once

#include "AbstractBlock.h"
#include "Collision.h"
#include <vector>
#include <memory>


//�u���b�N�Ǘ��N���X
class BlockManager {

private:
	static const int LEVEL_UP_SPEED;					//���x�����オ��Ԋu
	std::vector<std::unique_ptr<AbstractBlock>> blocks;	//�Ǘ�����u���b�N�̔z��
	int count;											//�o�߃t���[����
	int level;											//��Փx

public:
	BlockManager(std::unique_ptr<Collision> &_collision);
	~BlockManager();

	void update();			//�X�V
	void render() const;	//�`��

private:
	void destroyCheck();	//���Ă���u���b�N�����邩�̊m�F
};