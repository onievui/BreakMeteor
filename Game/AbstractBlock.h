#pragma once

#include "Vector2.h"
#include "Color.h"
#include <memory>

class AbstractBlock {

protected:
	Vector2 pos;                    //’†SÀ•W
	float width;                    //‰¡•
	float height;                   //c•
	int hp;			                //‘Ï‹v—Í
	std::unique_ptr<Color> color;	//F

public:
	AbstractBlock() = default;
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};