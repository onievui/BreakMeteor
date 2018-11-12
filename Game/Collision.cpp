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

	//ボールとパドルの当たり判定
	float time, ref_normal;
	for (auto &ball : *balls) {
		if (Collider::collisionRect(*ball->getCollider(), *paddle->get()->getCollider(), &time, &ref_normal)) {
					ball->reflect(time, ref_normal);
		}
	}

	//ボールとブロックの当たり判定
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

