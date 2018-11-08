#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>

class AbstractBall {

protected:
	Vector2 pos;                            //中心座標
	Vector2 vel;                            //速度
	float radius;	                        //半径
	float angle;	                        //角度
	float speed;	                        //速度
	std::unique_ptr<RectCollider> collider;	//当たり判定
	std::unique_ptr<Color> color;	        //色

public:
	AbstractBall() = default;
	AbstractBall(const Vector2 &_pos,const Vector2 &_vel, const float _radius, const float _angle, const float _speed)
		: pos(_pos)
		, vel(_vel)
		, radius(_radius)
		, angle(_angle)
		, speed(_speed){}
	virtual ~AbstractBall() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};