#include "Collision.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Collision::Collision() {
}

/// <summary>
/// �X�V
/// </summary>
void Collision::update() {

	//�{�[���ƃp�h���̓����蔻��
	float time, ref_normal;
	for (auto &ball : *balls) {
		if (Collider::collisionRect(*ball->getCollider(), *paddle->get()->getCollider(), &time, &ref_normal)) {
					ball->reflect(time, ref_normal);
		}
	}

	//�{�[���ƃu���b�N�̓����蔻��
	for (auto &ball : *balls) {
		auto it = blocks->begin();
		auto end = blocks->end();
		for (; it != end;) {
			if (!it->get()->isDestroyed() && Collider::collisionRect(*ball->getCollider(), *it->get()->getCollider(), &time, &ref_normal)) {
				ball->reflect(time, ref_normal);
				it->get()->collisionBall();
			}
			++it;
		}
	}
}

/// <summary>
/// �p�h���̃|�C���^�̐ݒ�
/// </summary>
/// <param name="_paddle">�p�h���̃|�C���^</param>
void Collision::setPaddle(std::unique_ptr<Paddle> *_paddle) {
	paddle = _paddle;
}

/// <summary>
/// �{�[���z��̃|�C���^�̐ݒ�
/// </summary>
/// <param name="_balls">�{�[���z��̃|�C���^</param>
void Collision::setBalls(std::vector<std::unique_ptr<AbstractBall>>* _balls) {
	balls = _balls;
}

/// <summary>
/// �u���b�N�z��̃|�C���^�̐ݒ�
/// </summary>
/// <param name="_blocks">�u���b�N�z��̃|�C���^</param>
void Collision::setBlocks(std::vector<std::unique_ptr<AbstractBlock>>* _blocks) {
	blocks = _blocks;
}

