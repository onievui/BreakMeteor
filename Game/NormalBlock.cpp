#include "NormalBlock.h"


NormalBlock::NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const unsigned int _color) {
	pos    = _pos;
	width  = _width;
	height = _height;
	hp     = _hp;
	color  = _color;
}

NormalBlock::~NormalBlock() {

}

void NormalBlock::update() {

}

void NormalBlock::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color, true);
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, COLOR_WHITE, false);
}
