#pragma once

#include "AbstractBall.h"


class NormalBall : public AbstractBall {

public:
	NormalBall();
	~NormalBall();

	void update() override;
	void draw() const override;
};