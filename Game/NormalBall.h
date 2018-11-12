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
	void reflect(const float _time, const float _ref_surface) override;
};