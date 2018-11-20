#pragma once

#include "AbstractBlock.h"


//���[�u�u���b�N�N���X
class MoveBlock : public AbstractBlock {

private:
	float moveSpeed;	//�ړ����x
	bool faceLeft;		//���������ǂ���

public:
	MoveBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color);
	~MoveBlock();

	void update() override;			        //�X�V
	void draw() const override;		        //�`��
	void onHitBall(float _time) override;	//�{�[���ƏՓ˂����Ƃ��̏���
	int getScore() const override;			//�X�R�A�̎擾

private:
	void collisionWall();		//�ǂƂ̓����蔻��
};