#pragma once

#include "AbstractBall.h"


//�m�[�}���{�[���N���X
class NormalBall : public AbstractBall {
	
private:
	void collisionWall();	//�ǂƏՓ˂����Ƃ��̏���
	
public:
	NormalBall();
	~NormalBall();

	void update() override;	                                            //�X�V
	void draw() const override;                                         //�`��
	void reflect(const float _time, const float _ref_surface) override;	//����
};