#include "Collision.h"

Collision::Collision(std::unique_ptr<Paddle>& _paddle, std::unique_ptr<BallManager>& _ball_manager, std::unique_ptr<BlockManager>& _block_manager) 
	: paddle(_paddle)
	, ballManager(_ball_manager)
	, blockManager(_block_manager) {
}

void Collision::update() {

}
