#include "NormalBlock.h"


NormalBlock::NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color) {
	pos      = _pos;
	vel      = Vector2(0, 0);
	width    = _width;
	height   = _height;
	hp       = _hp;
	color    = std::move(_color);
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, width, height);
}

NormalBlock::~NormalBlock() {

}

void NormalBlock::update() {

}

void NormalBlock::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, ColorCode::COLOR_WHITE, false);
}

bool NormalBlock::collisionBall() {
	hp -= 1;
	if (hp <= 0) {
		return true;
	}
	return false;
}
