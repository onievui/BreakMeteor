#pragma once

#include "BallManager.h"
#include "NormalBall.h"


BallManager::BallManager() {
	balls.emplace_back(std::make_unique<NormalBall>());
}

BallManager::~BallManager() {

}

void BallManager::update() {
	for (auto &ball : balls) {
		ball->update();
	}
}

void BallManager::render() const {
	for (auto &ball : balls) {
		ball->draw();
	}
}
