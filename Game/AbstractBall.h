#pragma once

#include "Vector2.h"
#include "Color.h"
#include <memory>

class AbstractBall {

protected:
	Vector2 pos;                    //中心座標
	Vector2 vel;                    //速度
	float radius;	                //半径
	float angle;	                //角度
	float speed;	                //速度
	std::unique_ptr<Color> color;	//色

public:
	AbstractBall() = default;
	virtual ~AbstractBall() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};