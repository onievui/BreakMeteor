#pragma once

#include "AbstractBall.h"
#include "Collision.h"
#include <vector>
#include <memory>

class BallManager {

private:
	std::vector<std::unique_ptr<AbstractBall>> balls;

public:
	BallManager(std::unique_ptr<Collision> &_collision);
	~BallManager();

	void update();
	void render() const;

	
};