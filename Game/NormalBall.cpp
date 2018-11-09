#pragma once
#include "NormalBall.h"
#include "Field.h"



static constexpr float PI = DX_PI_F;

NormalBall::NormalBall()
	: AbstractBall::AbstractBall(
		Vector2(320,300),
		Vector2(0,0),
		5.f,
		PI / 4,
		4.f
	) {
	//速度優先の為、イニシャライザ未使用
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, radius, radius);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_YELLOW);
	
}

NormalBall::~NormalBall() {

}

void NormalBall::update() {
	pos += vel;
	collisionWall();
	vel = { 0,0 };
	vel = Vector2::createWithAngleNorm(angle, speed);
}

void NormalBall::draw() const {
	DrawCircleAA(pos.x, pos.y, radius, 16, color->getColor(), true);
}

void NormalBall::reflect(const float _time, const float _ref_surface) {
	pos += vel * _time;
	//angle = PI * 2 - (angle - _ref_surface) + _ref_surface;
	//vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
	if (_ref_surface==0) {
		angle = PI * 2 - angle;
	}
	else  {
		if (angle < PI) {
			angle = PI - angle;
		}
		else {
			angle = PI * 3 - angle;
		}
	}
	vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
}

void NormalBall::collisionWall() {
	if (pos.x - radius <= FIELD::LEFT || pos.x + radius >= FIELD::RIGHT) {
		if (angle < PI) {
			angle = PI - angle;
		}
		else {
			angle = PI * 3 - angle;
		}
	}
	if (pos.y - radius <= FIELD::TOP || pos.y + radius >= FIELD::BOTTOM) {
		angle = PI * 2 - angle;
	}
}
