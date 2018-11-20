#include "AbstractBlock.h"


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_pos">座標</param>
/// <param name="_width">横幅</param>
/// <param name="_height">縦幅</param>
/// <param name="_hp">耐久力</param>
/// <param name="_score">スコア</param>
AbstractBlock::AbstractBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score)
	: pos(_pos)
	, vel(Vector2(0, 0))
	, angle(0)
	, width(_width)
	, height(_height)
	, hp(_hp)
	, score(_score) 
	, isValid(true) {
}

/// <summary>
///	当たり判定の取得
/// </summary>
/// <returns>
/// 当たり判定のポインタ
/// </returns>
RectRotateCollider* AbstractBlock::getCollider() const {
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
