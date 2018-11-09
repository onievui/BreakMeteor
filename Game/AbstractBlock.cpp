#include "AbstractBlock.h"

RectCollider* AbstractBlock::getCollider() const {
	return collider.get();
}
