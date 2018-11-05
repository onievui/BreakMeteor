#pragma once

#include "AbstractBlock.h"


class NormalBlock : public AbstractBlock {

public:
	NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color);
	~NormalBlock();

	void update() override;
	void draw() const override;
};