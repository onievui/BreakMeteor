#include "NormalBall.h"
#include "Field.h"



static const float PI = DX_PI_F;

NormalBall::NormalBall() {
	pos = { 320,300 };
	vel = { 0,0 };
	radius = 5;
	angle = PI / 4;
	speed = 4;
	color = std::make_unique<RGBColor>(0, 0, 0);
	color->setColor(ColorCode::COLOR_YELLOW);
}

NormalBall::~NormalBall() {

}

void NormalBall::update() {
	collisionWall();
	vel = { 0,0 };
	vel = Vector2::createWithAngleNorm(angle, speed);
	pos += vel;
}

void NormalBall::draw() const {
	DrawCircleAA(pos.x, pos.y, radius, 16, color->getColor(), true);
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
