#include "Collision.h"

Collision::Collision() {
}

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

	////ボールとパドルの当たり判定
	//auto it = ballManager->getBallsBigin();
	//auto end = ballManager->getBallsEnd();
	//float time, ref_angle;
	//for (; it != end; ++it) {
	//	if (Collider::collisionRect(*it->get()->getCollider(), *paddle->getCollider(), &time, &ref_angle)) {
	//		it->get()->reflect(time, ref_angle);
	//	}
	//}

	////ボールとブロックの当たり判定
	//it = ballManager->getBallsBigin();
	//end = ballManager->getBallsEnd();
	//auto it2 = blockManager->getBlocksBigin();
	//auto end2 = blockManager->getBlocksEnd();
	//for (; it != end; ++it) {
	//	for (; it2 != end2;) {
	//		if (Collider::collisionRect(*it->get()->getCollider(), *it2->get()->getCollider(), &time, &ref_angle)) {
	//			it->get()->reflect(time, ref_angle);
	//			if (blockManager->collisionBallIt(&it2)) {
	//				
	//			}
	//		}
	//		++it2;
	//	}
	//}
}

void Collision::setPaddle(std::unique_ptr<Paddle> *_paddle) {
	paddle = _paddle;
}

void Collision::setBalls(std::vector<std::unique_ptr<AbstractBall>>* _balls) {
	balls = _balls;
}

void Collision::setBlocks(std::vector<std::unique_ptr<AbstractBlock>>* _blocks) {
	blocks = _blocks;
}

