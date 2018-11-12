#pragma once
#include "Vector2.h"


//�R���C�_�[�̎��
enum COLLIDER_TYPE {
	COLLIDER_TYPE_NONE,
	COLLIDER_TYPE_RECT,
	COLLIDER_TYPE_NUM
};


class RectCollider;

//�R���C�_�[�N���X
class Collider {

public:
	const COLLIDER_TYPE type;	//�R���C�_�[�̎��

public:
	Collider(const COLLIDER_TYPE _type) : type(_type){}
	virtual ~Collider() = default;

	static bool collisionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_normal);	//��`���m�̓����蔻��
};

//��`�R���C�_�[
class RectCollider : public Collider {

public:
	Vector2 *pos;	//���W
	Vector2 offset;	//�I�t�Z�b�g
	Vector2 *vel;	//���x
	float width;	//����
	float height;	//�c��

public:
	RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float &_width, const float &_height);
	~RectCollider() = default;

};





