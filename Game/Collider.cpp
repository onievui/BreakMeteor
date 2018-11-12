#pragma once

#include "Collider.h"
#include "MyMath.h"


/// <summary>
/// ��`���m�̏Փ˔���
/// </summary>
/// <param name="_rect1">��`1</param>
/// <param name="_rect2">��`2</param>
/// <param name="_time">�Փ˂܂ł̎���</param>
/// <param name="_ref_angle">���ˊp</param>
/// <returns>
/// �Փ˂������ǂ���
/// </returns>
bool Collider::collisionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_normal) {
	//�e�����̏Փ˂���܂ł̎���
	float xmin, xmax, ymin, ymax;
	xmin = xmax = ymin = ymax = -1.f;
	//���W�̌v�Z
	Vector2 pos1 = *_rect1.pos + _rect1.offset;
	Vector2 pos2 = *_rect2.pos + _rect2.offset;
	//_rect1���猩�����Α��x
	Vector2 vel = *_rect1.vel - *_rect2.vel;

	//X�����̏Փ˂���܂ł̎���
	if (!FloatEqual(vel.x ,0.f)) {
		xmin = ((pos2.x - _rect2.width / 2) - (pos1.x + _rect1.width / 2)) / vel.x;
		xmax = ((pos2.x + _rect2.width / 2) - (pos1.x - _rect1.width / 2)) / vel.x;
		if (vel.x < 0) {
			std::swap(xmin, xmax);
		}
	}
	//X�����̑��x��0�̏ꍇ
	else {
		if ((pos1.x + _rect2.width / 2) > (pos2.x - _rect1.width / 2) &&
			(pos1.x - _rect2.width / 2) < (pos2.x + _rect1.width / 2)) {
			xmin = 0.0f;
			xmax = 1.0f;
		}
	}

	//Y�����̏Փ˂���܂ł̎���
	if (!FloatEqual(vel.y, 0.f)) {
		ymin = ((pos2.y - _rect2.height / 2) - (pos1.y + _rect1.height / 2)) / vel.y;
		ymax = ((pos2.y + _rect2.height / 2) - (pos1.y - _rect1.height / 2)) / vel.y;
		if (vel.y < 0) {
			std::swap(ymin, ymax);
		}
	}
	//Y�����̑��x��0�̏ꍇ
	else {
		if ((pos1.y + _rect2.height / 2) > (pos2.y - _rect1.height / 2) &&
			(pos1.y - _rect2.height / 2) < (pos2.y + _rect1.height / 2)) {
			ymin = 0.0f;
			ymax = 1.0f;
		}
	}

	//�Փ˔���
	if (xmin <= 1.0f && xmax >= 0.0f &&
		ymin <= 1.0f && ymax >= 0.0f &&
		xmin <= ymax && ymin <= xmax) {
		//X��������ɏՓ˂��Ă���
		if (xmin > ymin) {
			*_time = xmin;
			if (pos1.x < pos2.x) {
				*_ref_normal = PI;
			}
			else {
				*_ref_normal = 0.f;
			}
		}
		//Y��������ɏՓ˂��Ă���
		else {
			*_time = ymin;
			if (pos1.y < pos2.y) {
				*_ref_normal = PI * 1.5f;
			}
			else {
				*_ref_normal = PI * 0.5f;
			}
		}
		return true;
	}
	return false;
}


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_pos">���W�̃|�C���^</param>
/// <param name="_offset">�I�t�Z�b�g</param>
/// <param name="_vel">���x�̃|�C���^</param>
/// <param name="_width">����</param>
/// <param name="_height">�c��</param>
RectCollider::RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float &_width, const float &_height) 
	: Collider(COLLIDER_TYPE_RECT)
	, pos(_pos)
	, offset(_offset)
	, vel(_vel)
	, width(_width)
	, height(_height) {
	
}
