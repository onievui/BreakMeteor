#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>

class AbstractBall {

protected:
	Vector2 pos;                                //中心座標
	Vector2 vel;                                //速度
	float radius;	                            //半径
	float angle;	                            //角度
	float speed;	                            //速度
	std::unique_ptr<CircleCollider> collider;	//当たり判定
	std::unique_ptr<Color> color;	            //色

public:
	AbstractBall() = default;
	AbstractBall(const Vector2 &_pos, const Vector2 &_vel, const float _radius, const float _angle, const float _speed);
	virtual ~AbstractBall() = default;

	virtual void update() = 0;												                            //更新
	virtual void draw() const = 0;											                            //描画
	virtual void reflect(const float _time, const float _ref_angle, const float _hit_pos_x = -1.f) = 0;	//反射
	CircleCollider* getCollider() const;										                        //当たり判定の取得
};