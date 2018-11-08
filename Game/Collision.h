#pragma once

#include "Paddle.h"
#include "BallManager.h"
#include "BlockManager.h"


class Collision {

private:
	std::unique_ptr<Paddle> &paddle;
	std::unique_ptr<BallManager> &ballManager;
	std::unique_ptr<BlockManager> &blockManager;

public:
	Collision(std::unique_ptr<Paddle> &_paddle, std::unique_ptr<BallManager> &_ball_manager, std::unique_ptr<BlockManager> &_block_manager);
	~Collision() = default;

	void update();

};