#pragma once
#include "Vector2.h"



enum COLLIDER_TYPE {
	COLLIDER_TYPE_NONE,
	COLLIDER_TYPE_RECT,
	COLLIDER_TYPE_NUM
};


class RectCollider;


class Collider {

public:
	const COLLIDER_TYPE type;

public:
	Collider(const COLLIDER_TYPE _type) : type(_type){}
	virtual ~Collider() = default;

	static bool collisionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_normal);
};


class RectCollider : public Collider {

public:
	Vector2 *pos;
	Vector2 offset;
	Vector2 *vel;
	float width;
	float height;

public:
	//RectCollider() {}
	RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float &_width, const float &_height);
	~RectCollider() = default;

};





