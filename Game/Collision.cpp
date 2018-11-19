#include "Collision.h"


/// <summary>
/// コンストラクタ
/// </summary>
Collision::Collision() {
}

/// <summary>
/// 更新
/// </summary>
void Collision::update() {

	//パドルの移動制限
	RectRotateCollider moved_paddle = *paddle->get()->getCollider();
	Vector2 paddle_moved_pos = *moved_paddle.pos + *moved_paddle.vel;
	float paddle_rotated_angle = paddle->get()->getRotatedAngle();
	moved_paddle.pos = &paddle_moved_pos;
	moved_paddle.angle = &paddle_rotated_angle;
	for (auto &ball : *balls) {
		//移動後にボールと衝突していたら移動しないようにする
		if (Collider::collisionCircleRectRotate(*ball->getCollider(), moved_paddle)) {
			paddle->get()->cancelMove();
			break;
		}
	}
	paddle->get()->rotate();

	//ボールとパドルの当たり判定
	float time, ref_normal;
	for (auto &ball : *balls) {
		if (Collider::collisionCircleRectRotate(*ball->getCollider(), *paddle->get()->getCollider(), &time, &ref_normal)) {
			ball->reflect(time, ref_normal, paddle->get()->getPos().x);
			paddle->get()->onHitBall(time);
		}
	}

	//ボールとブロックの当たり判定
	for (auto &ball : *balls) {
		for (auto &block : *blocks) {
			if (!block->isDestroyed() && Collider::collisionCircleRectRotate(*ball->getCollider(), *block->getCollider(), &time, &ref_normal)) {
				ball->reflect(time, ref_normal);
				block->onHitBall(time);
			}
		}
	}

	//パドルとブロックの当たり判定
	for (auto &block : *blocks) {
		if (!block->isDestroyed() && Collider::collisionRectRotate(*paddle->get()->getCollider(), *block->getCollider())) {
			paddle->get()->onHitBlock();
		}
	}
}

/// <summary>
/// パドルのポインタの設定
/// </summary>
/// <param name="_paddle">パドルのポインタ</param>
void Collision::setPaddle(std::unique_ptr<Paddle> *_paddle) {
	paddle = _paddle;
}

/// <summary>
/// ボール配列のポインタの設定
/// </summary>
/// <param name="_balls">ボール配列のポインタ</param>
void Collision::setBalls(std::vector<std::unique_ptr<AbstractBall>>* _balls) {
	balls = _balls;
}

/// <summary>
/// ブロック配列のポインタの設定
/// </summary>
/// <param name="_blocks">ブロック配列のポインタ</param>
void Collision::setBlocks(std::vector<std::unique_ptr<AbstractBlock>>* _blocks) {
	blocks = _blocks;
}

