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
bool Collider::CollsionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_angle) {
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
		if (_rect1.pos->x > _rect2.pos->x) {
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
		if (_rect1.pos->y > _rect2.pos->y) {
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
			*_ref_angle = 0;
		}
		//Y��������ɏՓ˂��Ă���
		else {
			*_time = ymin;
			*_ref_angle = DX_PI_F / 2;
		}

		return true;
	}
	
	return false;
}



RectCollider::RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float &_width, const float &_height) 
	: Collider(COLLIDER_TYPE_RECT)
	, pos(_pos)
	, offset(_offset)
	, vel(_vel)
	, width(_width)
	, height(_height) {
	
}
