#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>

class AbstractBall {

protected:
	Vector2 pos;                            //���S���W
	Vector2 vel;                            //���x
	float radius;	                        //���a
	float angle;	                        //�p�x
	float speed;	                        //���x
	std::unique_ptr<RectCollider> collider;	//�����蔻��
	std::unique_ptr<Color> color;	        //�F

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