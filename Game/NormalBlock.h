#pragma once

#include "AbstractBlock.h"


//�m�[�}���u���b�N�N���X
class NormalBlock : public AbstractBlock {

public:
	NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color);
	~NormalBlock();

	void update() override;			//�X�V
	void draw() const override;		//�`��
	void collisionBall() override;	//�{�[���ƏՓ˂����Ƃ��̏���
};