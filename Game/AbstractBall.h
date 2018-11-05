#pragma once

#include "Vector2.h"
#include "Color.h"
#include <memory>

class AbstractBall {

protected:
	Vector2 pos;                    //���S���W
	Vector2 vel;                    //���x
	float radius;	                //���a
	float angle;	                //�p�x
	float speed;	                //���x
	std::unique_ptr<Color> color;	//�F

public:
	AbstractBall() = default;
	virtual ~AbstractBall() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};