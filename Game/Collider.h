#pragma once
#include "Vector2.h"


//コライダーの種類
enum COLLIDER_TYPE {
	COLLIDER_TYPE_NONE,
	COLLIDER_TYPE_RECT,
	COLLIDER_TYPE_NUM
};


class RectCollider;

//コライダークラス
class Collider {

public:
	const COLLIDER_TYPE type;	//コライダーの種類

public:
	Collider(const COLLIDER_TYPE _type) : type(_type){}
	virtual ~Collider() = default;

	static bool collisionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_normal);	//矩形同士の当たり判定
};

//矩形コライダー
class RectCollider : public Collider {

public:
	Vector2 *pos;	//座標
	Vector2 offset;	//オフセット
	Vector2 *vel;	//速度
	float width;	//横幅
	float height;	//縦幅

public:
	RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float &_width, const float &_height);
	~RectCollider() = default;

};





