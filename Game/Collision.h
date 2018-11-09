#pragma once

#include "Paddle.h"
#include "AbstractBall.h"
#include "AbstractBlock.h"
#include <vector>


class Collision {

private:
	std::unique_ptr<Paddle> *paddle;
	std::vector<std::unique_ptr<AbstractBall>> *balls;
	std::vector<std::unique_ptr<AbstractBlock>> *blocks;

public:
	Collision();
	~Collision() = default;

	void update();

	void setPaddle(std::unique_ptr<Paddle> *_paddle);
	void setBalls(std::vector<std::unique_ptr<AbstractBall>> *_balls);
	void setBlocks(std::vector<std::unique_ptr<AbstractBlock>> *_blocks);

};