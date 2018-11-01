#pragma once

#include "Vector2.h"

class AbstractBlock {

protected:
	Vector2 pos;        //’†SÀ•W
	float width;        //‰¡•
	float height;       //c•
	int hp;				//‘Ï‹v—Í
	unsigned int color; //F

public:
	AbstractBlock() = default;
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;

	virtual void draw() const = 0;
};