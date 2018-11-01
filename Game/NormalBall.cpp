#include "NormalBall.h"



NormalBall::NormalBall() {
	pos = { 320,300 };
	vel = { 0,0 };
	radius = 3;
	angle = DX_PI_F / 2;
	speed = 3;
	color = COLOR_YELLOW;
}

NormalBall::~NormalBall() {
}

void NormalBall::update() {
	vel = { 0,0 };
	vel = Vector2::createWithAngleNorm(angle, speed);
	pos += vel;
}

void NormalBall::draw() const {
	DrawCircleAA(pos.x, pos.y, radius, 16, color, true);
}
