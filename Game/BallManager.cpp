#pragma once

#include "BallManager.h"
#include "NormalBall.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_collision">
/// �����蔻��N���X�̎Q��
/// </param>
BallManager::BallManager(std::unique_ptr<Collision>& _collision) {

	//�����蔻��p�ɔz��̃|�C���^��n��
	_collision->setBalls(&balls);

	//for(int i=0;i<1000000;i++)
	balls.emplace_back(std::make_unique<NormalBall>());
	//int a = 10;
}

BallManager::~BallManager() {

}

/// <summary>
/// �X�V
/// </summary>
void BallManager::update() {
	for (auto &ball : balls) {
		ball->update();
		
	}
	
}

/// <summary>
/// �`��
/// </summary>
void BallManager::render() const {
	for (auto &ball : balls) {
		ball->draw();
	}
}

