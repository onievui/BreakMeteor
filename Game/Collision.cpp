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

	//�p�h���̈ړ�����
	RectRotateCollider moved_paddle = *paddle->get()->getCollider();
	Vector2 paddle_moved_pos = *moved_paddle.pos + *moved_paddle.vel;
	float paddle_rotated_angle = paddle->get()->getRotatedAngle();
	moved_paddle.pos = &paddle_moved_pos;
	moved_paddle.angle = &paddle_rotated_angle;
	for (auto &ball : *balls) {
		//�ړ���Ƀ{�[���ƏՓ˂��Ă�����ړ����Ȃ��悤�ɂ���
		if (Collider::collisionCircleRectRotate(*ball->getCollider(), moved_paddle)) {
			paddle->get()->cancelMove();
			break;
		}
	}
	paddle->get()->rotate();

	//�{�[���ƃp�h���̓����蔻��
	float time, ref_normal;
	for (auto &ball : *balls) {
		if (Collider::collisionCircleRectRotate(*ball->getCollider(), *paddle->get()->getCollider(), &time, &ref_normal)) {
					ball->reflect(time, ref_normal, paddle->get()->getPos().x);
					paddle->get()->onHitBall(time);
		}
	}

	//�{�[���ƃu���b�N�̓����蔻��
	for (auto &ball : *balls) {
		auto it = blocks->begin();
		auto end = blocks->end();
		for (; it != end;) {
			if (!it->get()->isDestroyed() && Collider::collisionCircleRectRotate(*ball->getCollider(), *it->get()->getCollider(), &time, &ref_normal)) {
				ball->reflect(time, ref_normal);
				it->get()->onHitBall();
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

