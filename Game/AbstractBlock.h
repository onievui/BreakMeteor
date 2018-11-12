#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Collider.h"
#include <memory>

//�u���b�N�̒��ۃN���X
class AbstractBlock {

protected:
	Vector2 pos;                            //���S���W
	Vector2 vel;							//���x
	float width;                            //����
	float height;                           //�c��
	int hp;			                        //�ϋv��
	bool isValid;							//���݂��邩
	std::unique_ptr<Color> color;	        //�F
	std::unique_ptr<RectCollider> collider; //�����蔻��

public:
	AbstractBlock() = default;
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;			//�X�V
	virtual void draw() const = 0;		//�`��
	virtual void collisionBall() = 0;	//�{�[���Ƃ̏Փˏ���
	RectCollider* getCollider() const;	//�����蔻��̎擾
	bool isDestroyed() const;			//���݂��邩�ǂ���
};