#pragma once

#include "AbstractBlock.h"
#include "Collision.h"
#include <vector>
#include <memory>


//�u���b�N�Ǘ��N���X
class BlockManager {

private:
	std::vector<std::unique_ptr<AbstractBlock>> blocks;	//�Ǘ�����u���b�N�̔z��
	int count;											//�o�߃t���[����

public:
	BlockManager(std::unique_ptr<Collision> &_collision);
	~BlockManager();

	void update();			//�X�V
	void render() const;	//�`��

private:
	void destroyCheck();	//���Ă���u���b�N�����邩�̊m�F
};