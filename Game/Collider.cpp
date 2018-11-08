#pragma once

#include "Collider.h"
#include "MyMath.h"


/// <summary>
/// 矩形同士の衝突判定
/// </summary>
/// <param name="_rect1">矩形1</param>
/// <param name="_rect2">矩形2</param>
/// <param name="_time">衝突までの時間</param>
/// <param name="_ref_angle">反射角</param>
/// <returns>
/// 衝突したかどうか
/// </returns>
bool Collider::CollsionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_angle) {
	//各方向の衝突するまでの時間
	float xmin, xmax, ymin, ymax;
	xmin = xmax = ymin = ymax = -1.f;
	//座標の計算
	Vector2 pos1 = *_rect1.pos + _rect1.offset;
	Vector2 pos2 = *_rect2.pos + _rect2.offset;
	//_rect1から見た相対速度
	Vector2 vel = *_rect1.vel - *_rect2.vel;

	//X方向の衝突するまでの時間
	if (!FloatEqual(vel.x ,0.f)) {
		xmin = ((pos2.x - _rect2.width / 2) - (pos1.x + _rect1.width / 2)) / vel.x;
		xmax = ((pos2.x + _rect2.width / 2) - (pos1.x - _rect1.width / 2)) / vel.x;
		if (_rect1.pos->x > _rect2.pos->x) {
			std::swap(xmin, xmax);
		}
	}
	//X方向の速度が0の場合
	else {
		if ((pos1.x + _rect2.width / 2) > (pos2.x - _rect1.width / 2) &&
			(pos1.x - _rect2.width / 2) < (pos2.x + _rect1.width / 2)) {
			xmin = 0.0f;
			xmax = 1.0f;
		}
	}

	//Y方向の衝突するまでの時間
	if (!FloatEqual(vel.y, 0.f)) {
		ymin = ((pos2.y - _rect2.height / 2) - (pos1.y + _rect1.height / 2)) / vel.y;
		ymax = ((pos2.y + _rect2.height / 2) - (pos1.y - _rect1.height / 2)) / vel.y;
		if (_rect1.pos->y > _rect2.pos->y) {
			std::swap(ymin, ymax);
		}
	}
	//Y方向の速度が0の場合
	else {
		if ((pos1.y + _rect2.height / 2) > (pos2.y - _rect1.height / 2) &&
			(pos1.y - _rect2.height / 2) < (pos2.y + _rect1.height / 2)) {
			ymin = 0.0f;
			ymax = 1.0f;
		}
	}

	//衝突判定
	if (xmin <= 1.0f && xmax >= 0.0f &&
		ymin <= 1.0f && ymax >= 0.0f &&
		xmin <= ymax && ymin <= xmax) {
		//X方向が先に衝突している
		if (xmin > ymin) {
			*_time = xmin;
			*_ref_angle = 0;
		}
		//Y方向が先に衝突している
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
