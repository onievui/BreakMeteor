#pragma once

#include "Vector2.h"

class AbstractBall {

protected:
	Vector2 pos;        //���S���W
	Vector2 vel;        //���x
	float radius;		//���a
	float angle;		//�p�x
	float speed;		//���x
	unsigned int color; //�F

public:
	AbstractBall() = default;
	virtual ~AbstractBall() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};