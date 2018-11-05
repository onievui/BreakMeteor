#pragma once

#include "AbstractBall.h"


class NormalBall : public AbstractBall {
	
private:
	void collisionWall();

public:
	NormalBall();
	~NormalBall();

	void update() override;
	void draw() const override;
};