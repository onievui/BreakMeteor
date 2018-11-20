#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Collider.h"
#include <memory>

//�u���b�N�̒��ۃN���X
class AbstractBlock {

protected:
	Vector2 pos;                                  //���S���W
	Vector2 vel;							      //���x
	float angle;								  //�p�x
	float width;                                  //����
	float height;                                 //�c��
	int hp;			                              //�ϋv��
	int score;									  //�X�R�A
	bool isValid;							      //���݂��邩
	std::unique_ptr<Color> color;	              //�F
	std::unique_ptr<RectRotateCollider> collider; //�����蔻��

public:
	AbstractBlock() = default;
	AbstractBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score);
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;			        //�X�V
	virtual void draw() const = 0;		        //�`��
	virtual void onHitBall(float _time) = 0;	//�{�[���Ƃ̏Փˏ���
	RectRotateCollider* getCollider() const;	//�����蔻��̎擾
	virtual int getScore() const = 0;			//�X�R�A�̎擾
	bool isDestroyed() const;			        //���݂��邩�ǂ���
};