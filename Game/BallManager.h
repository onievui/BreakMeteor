#pragma once

#include "AbstractBall.h"
#include <vector>
#include <memory>

class BallManager {

private:
	std::vector<std::unique_ptr<AbstractBall>> balls;

public:
	BallManager();
	~BallManager();

	void update();

	void render() const;
};