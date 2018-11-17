#include "AbstractBall.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_pos">���W</param>
/// <param name="_vel">���x</param>
/// <param name="_radius">���a</param>
/// <param name="_angle">�p�x</param>
/// <param name="_speed">���x</param>
AbstractBall::AbstractBall(const Vector2 &_pos, const Vector2 &_vel, const float _radius, const float _angle, const float _speed)
	: pos(_pos)
	, vel(_vel)
	, radius(_radius)
	, angle(_angle)
	, speed(_speed) {
}

/// <summary>
/// �����蔻��̎擾
/// </summary>
/// <returns>
/// �����蔻��̃|�C���^
/// </returns>
CircleCollider* AbstractBall::getCollider() const {
	return collider.get();
}
