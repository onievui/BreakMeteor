#pragma once

#include "AbstractBlock.h"


//��]�u���b�N�N���X
class RotateBlock : public AbstractBlock {

private:
	float rotateSpeed;			//��]�X�s�[�h

public:
	RotateBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color);
	~RotateBlock();

	void update() override;			        //�X�V
	void draw() const override;		        //�`��
	void onHitBall(float _time) override;	//�{�[���ƏՓ˂����Ƃ��̏���
	int getScore() const override;				//�X�R�A�̎擾
};