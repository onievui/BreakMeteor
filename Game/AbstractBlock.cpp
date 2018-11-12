#include "AbstractBlock.h"

/// <summary>
///	当たり判定の取得
/// </summary>
/// <returns>
/// 当たり判定のポインタ
/// </returns>
RectCollider* AbstractBlock::getCollider() const {
	return collider.get();
}

/// <summary>
/// ブロックが存在するか
/// </summary>
/// <returns>
/// true:存在する
/// false:存在しない
/// </returns>
bool AbstractBlock::isDestroyed() const {
	return !isValid;
}
