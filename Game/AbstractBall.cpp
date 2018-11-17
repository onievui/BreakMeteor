#include "AbstractBall.h"


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_pos">座標</param>
/// <param name="_vel">速度</param>
/// <param name="_radius">半径</param>
/// <param name="_angle">角度</param>
/// <param name="_speed">速度</param>
AbstractBall::AbstractBall(const Vector2 &_pos, const Vector2 &_vel, const float _radius, const float _angle, const float _speed)
	: pos(_pos)
	, vel(_vel)
	, radius(_radius)
	, angle(_angle)
	, speed(_speed) {
}

/// <summary>
/// 当たり判定の取得
/// </summary>
/// <returns>
/// 当たり判定のポインタ
/// </returns>
CircleCollider* AbstractBall::getCollider() const {
	return collider.get();
}
