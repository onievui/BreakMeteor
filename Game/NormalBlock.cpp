#include "NormalBlock.h"


NormalBlock::NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color) {
	pos    = _pos;
	width  = _width;
	height = _height;
	hp     = _hp;
	color = std::move(_color);
}

NormalBlock::~NormalBlock() {

}

void NormalBlock::update() {

}

void NormalBlock::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, ColorCode::COLOR_WHITE, false);
}
