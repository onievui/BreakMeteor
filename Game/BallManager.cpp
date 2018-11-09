#pragma once

#include "BallManager.h"
#include "NormalBall.h"



BallManager::BallManager(std::unique_ptr<Collision>& _collision) {

	//当たり判定用に配列のポインタを渡す
	_collision->setBalls(&balls);

	//for(int i=0;i<1000000;i++)
	balls.emplace_back(std::make_unique<NormalBall>());
	//int a = 10;
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

