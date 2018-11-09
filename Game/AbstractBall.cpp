#include "AbstractBall.h"

RectCollider* AbstractBall::getCollider() const {
	return collider.get();
}
