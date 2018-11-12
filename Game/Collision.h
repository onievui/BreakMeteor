#pragma once

#include "Paddle.h"
#include "AbstractBall.h"
#include "AbstractBlock.h"
#include <vector>


//�����蔻��N���X
class Collision {

private:
	std::unique_ptr<Paddle> *paddle;						//�p�h���ւ̃|�C���^
	std::vector<std::unique_ptr<AbstractBall>> *balls;		//�{�[���z��ւ̃|�C���^
	std::vector<std::unique_ptr<AbstractBlock>> *blocks;	//�u���b�N�z��ւ̃|�C���^

public:
	Collision();
	~Collision() = default;

	void update();	//�X�V

	void setPaddle(std::unique_ptr<Paddle> *_paddle);						//�p�h���̃|�C���^�̐ݒ�
	void setBalls(std::vector<std::unique_ptr<AbstractBall>> *_balls);		//�{�[���z��̃|�C���^�̐ݒ�
	void setBlocks(std::vector<std::unique_ptr<AbstractBlock>> *_blocks);	//�u���b�N�z��̃|�C���^�̐ݒ�

};