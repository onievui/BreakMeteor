#pragma once

#include "Collider.h"
#include "MyMath.h"


/// <summary>
/// 矩形同士の衝突判定
/// </summary>
/// <param name="_rect1">矩形1</param>
/// <param name="_rect2">矩形2</param>
/// <param name="_time">衝突までの時間</param>
/// <param name="_ref_normal">反射面の法線</param>
/// <returns>
/// 衝突したかどうか
/// </returns>
bool Collider::collisionRect(RectCollider &_rect1, RectCollider &_rect2, float *_time, float *_ref_normal) {
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
		if (vel.x < 0) {
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
		if (vel.y < 0) {
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
			if (pos1.x < pos2.x) {
				*_ref_normal = PI;
			}
			else {
				*_ref_normal = 0.f;
			}
		}
		//Y方向が先に衝突している
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
/// 回転矩形同士の衝突判定
/// </summary>
/// <param name="_rect_rotate1">回転矩形1</param>
/// <param name="_rect_rotate2">回転矩形2</param>
/// <returns>
/// 衝突したかどうか
/// </returns>
bool Collider::collisionRectRotate(RectRotateCollider &_rect_rotate1, RectRotateCollider &_rect_rotate2) {
	//中心座標の計算
	Vector2 pos1 = *_rect_rotate1.pos + _rect_rotate1.offset;
	Vector2 pos2 = *_rect_rotate2.pos + _rect_rotate2.offset;

	//各頂点座標の計算
	Vector2 vertex1[4];
	Vector2 vertex2[4];
	for (int i = 0; i < 4; ++i) {
		float x = _rect_rotate1.width / 2.f;
		float y = _rect_rotate1.height / 2.f;
		int xc = (i == 0 || i == 3) ? -1 : 1;
		int yc = (i < 2) ? -1 : 1;
		vertex1[i].x = x * xc*cosf(*_rect_rotate1.angle) - y * yc*sinf(*_rect_rotate1.angle) + pos1.x;
		vertex1[i].y = x * xc*sinf(*_rect_rotate1.angle) + y * yc*cosf(*_rect_rotate1.angle) + pos1.y;
		x = _rect_rotate2.width / 2.f;
		y = _rect_rotate2.height / 2.f;
		vertex2[i].x = x * xc*cosf(*_rect_rotate2.angle) - y * yc*sinf(*_rect_rotate2.angle) + pos2.x;
		vertex2[i].y = x * xc*sinf(*_rect_rotate2.angle) + y * yc*cosf(*_rect_rotate2.angle) + pos2.y;
	}

	//線分の交差判定
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (crossSegment(vertex1[i], vertex1[(i + 1) % 4], vertex2[j], vertex2[(j + 1) % 4])) {
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// 円と回転矩形の衝突判定（近似値）
/// </summary>
/// <param name="_circle">近似される円</param>
/// <param name="_rect_rotate">回転矩形</param>
/// <param name="_time">衝突までの時間</param>
/// <param name="_ref_normal">反射面の法線</param>
/// <returns>
/// 衝突したかどうか
/// </returns>
bool Collider::collisionCircleRectRotateApproximate(CircleCollider &_circle, RectRotateCollider &_rect_rotate, float *_time, float *_ref_normal) {

	//オフセットの計算
	Vector2 circle_pos = *_circle.pos + _circle.offset;
	Vector2 rect_rotate_pos = *_rect_rotate.pos + _rect_rotate.offset;

	//相対速度の計算
	Vector2 vel = *_circle.vel - *_rect_rotate.vel;

	//線分との判定用当たり判定
	CircleCollider circle(&circle_pos, Vector2(0, 0), &vel, _circle.radius);

	//各線分との衝突するまでの時間
	float t_a, t_b;

	//衝突状態
	bool isCollision = false;

	//各頂点座標との距離の計算
	Vector2 vertex[4];
	float vertex_distance[4];
	for (int i = 0; i < 4; ++i) {
		float x = _rect_rotate.width / 2.f;
		float y = _rect_rotate.height / 2.f;
		int xc = (i == 0 || i == 3) ? -1 : 1;
		int yc = (i < 2) ? -1 : 1;
		vertex[i] = Vector2::rotate(Vector2(x*xc, y*yc), *_rect_rotate.angle) + rect_rotate_pos;
		vertex_distance[i] = Vector2::distancePowPoint(circle_pos, vertex[i]);
	}

	DrawQuadrangleAA(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y, vertex[2].x, vertex[2].y, vertex[3].x, vertex[3].y, COLOR_BLUE, true);


	//回転矩形の左側に近い場合
	if (vertex_distance[0] < vertex_distance[1]) {
		if (collisionCircleSegment(circle, vertex[0], vertex[3], &t_a)) {
			isCollision = true;
			*_time = t_a;
			*_ref_normal = *_rect_rotate.angle + PI;
		}
	}
	else {
		if (collisionCircleSegment(circle, vertex[1], vertex[2], &t_a)) {
			isCollision = true;
			*_time = t_a;
			*_ref_normal = *_rect_rotate.angle;
		}
	}

	//回転矩形の上側に近い場合
	if (vertex_distance[1] < vertex_distance[2]) {
		if (collisionCircleSegment(circle, vertex[0], vertex[1], &t_b)) {
			isCollision = true;
			if (FloatEqual(t_a, -1.f) || t_b < t_a) {
				*_time = t_b;
				*_ref_normal = *_rect_rotate.angle + PI * 3 / 2;
			}
		}
	}
	else {
		if (collisionCircleSegment(circle, vertex[2], vertex[3], &t_b)) {
			isCollision = true;
			if (FloatEqual(t_a, -1.f) || t_b < t_a) {
				*_time = t_b;
				*_ref_normal = *_rect_rotate.angle + PI / 2;
			}
		}
	}

	//早く衝突したほうを返す
	*_time = t_a < t_b ? (t_a >= 0 ? t_a : t_b) : (t_b >= 0 ? t_b : t_a);

	return isCollision;

	////円を近似した矩形に変換
	//RectCollider rect1(&circle_pos, _circle.offset, &circle_vel, _circle.radius*2, _circle.radius*2);

	////回転矩形を矩形に変換
	//RectCollider rect2(_rect_rotate.pos, _rect_rotate.offset, &rect_rotate_vel, _rect_rotate.width, _rect_rotate.height);

	//DrawBoxAA(rect1.pos->x - rect1.width / 2, rect1.pos->y - rect1.height / 2, rect1.pos->x + rect1.width / 2, rect1.pos->y + rect1.height / 2, COLOR_BLUE, true);
	//DrawBoxAA(rect2.pos->x - rect2.width / 2, rect2.pos->y - rect2.height / 2, rect2.pos->x + rect2.width / 2, rect2.pos->y + rect2.height / 2, COLOR_BLUE, true);
	//DrawLineAA(rect1.pos->x, rect1.pos->y, rect2.pos->x, rect2.pos->y, COLOR_RED);
	//DrawLineAA(_circle.pos->x, _circle.pos->y, _rect_rotate.pos->x, _rect_rotate.pos->y, COLOR_GREEN);
	//if (*_rect_rotate.angle != 0)
	//	DrawLineAA(rect1.pos->x, rect1.pos->y, rect1.pos->x + rect1.vel->x*10, rect1.pos->y + rect1.vel->y*10, COLOR_PURPLE);

	////当たり判定を行う
	//if (collisionRect(rect1, rect2, _time, _ref_normal)) {
	//	*_ref_normal += *_rect_rotate.angle;
	//	return true;
	//}
	//return false;
}



/// <summary>
/// 線分の交差判定
/// </summary>
/// <param name="_p1">線分1の始点</param>
/// <param name="_p2">線分1の終点</param>
/// <param name="_p3">線分2の始点</param>
/// <param name="_p4">線分2の終点</param>
/// <returns>
/// 衝突したかどうか
/// </returns>
bool Collider::crossSegment(const Vector2 &_p1, const Vector2 &_p2, const Vector2 &_p3, const Vector2 &_p4) {
	float d = (_p2.x - _p1.x)*(_p4.y - _p3.y) - (_p2.y - _p1.y)*(_p4.x - _p3.x);
	if (FloatEqual(d, 0.f)) {
		return true;
	}
	float u = ((_p3.x - _p1.x)*(_p4.y - _p3.y) - (_p3.y - _p1.y)*(_p4.x - _p3.x)) / d;
	float v = ((_p3.x - _p1.x)*(_p2.y - _p1.y) - (_p3.y - _p1.y)*(_p2.x - _p1.x)) / d;

	if (u < 0.f || u > 1.f) {
		return false;
	}
	if (v < 0.f || v > 1.f) {
		return false;
	}
	return true;
}

bool Collider::collisionCircleSegment(const CircleCollider & _circle, Vector2 & _p1, Vector2 & _p2, float * _time) {
	//衝突までの時間
	float t0 = 0, t1 = 0;

	//交点の座標
	Vector2 cross_point;

	//線分のベクトル
	Vector2 seg_vec = _p2 - _p1;

	//X方向が0のベクトルがあるなら
	if (FloatEqual(_circle.vel->x, 0) || FloatEqual(seg_vec.x, 0)) {
		//両方のX方向のベクトルが0なら
		if (FloatEqual(_circle.vel->x, 0) && FloatEqual(seg_vec.x, 0)) {
			//衝突していない
			*_time = -1.f;
			return false;
		}
		//円のX方向ベクトルが0なら
		if (FloatEqual(_circle.vel->x, 0)) {
			//交点の座標を求める
			cross_point = { _circle.pos->x,(seg_vec.y / seg_vec.x)*(_circle.pos->x - _p1.x) + _p1.y };
			t0 = (cross_point.y - _circle.pos->y) / _circle.vel->y;
			t1 = (cross_point.x - _p1.x) / seg_vec.x;
		}
		//パドルのX方向ベクトルが0なら
		else {
			//交点の座標を求める
			cross_point = { _p1.x,(_circle.vel->y / _circle.vel->x)*(_p1.x - _circle.pos->x) + _circle.pos->y };
			t0 = (cross_point.x - _circle.pos->x) / _circle.vel->x;
			t1 = (cross_point.y - _p1.y) / seg_vec.y;
		}
		//交点が線分の中にあるかどうか
		if (t0 < 0 || t0 > 1 || t1 < 0 || t1 > 1) {
			//衝突していない
			*_time = -1.f;
			return false;
		}
		else {
			//円側の線分が当たるまでの時間が衝突するまでの時間
			*_time = t0;
		}
	}
	else {
		//線分の傾きを求める
		float a0 = _circle.vel->y / _circle.vel->x;
		float a1 = seg_vec.y / seg_vec.x;

		//傾きが平行かどうか
		if (FloatEqual(a0, a1) || FloatEqual(a0, -a1)) {
			//衝突していない
			*_time = -1.f;
			return false;
		}
		//交点の座標を求める
		cross_point.x = (a0*_circle.pos->x - a1 * _p1.x + _p1.y - _circle.pos->y) / (a0 - a1);
		cross_point.y = a0 * (cross_point.x - _circle.pos->x) + _circle.pos->y;

		t0 = (cross_point.x - _circle.pos->x) / _circle.vel->x;
		t1 = (cross_point.x - _p1.x) / seg_vec.x;
		//交点が線分の中にあるかどうか
		if (t0 < 0 || t0 > 1 || t1 < 0 || t1 > 1) {
			//衝突していない
			*_time = 1.f;
			return false;
		}
		else {
			//円側の線分が当たるまでの時間が衝突するまでの時間
			*_time = t0;
		}
	}
	return true;
}


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_pos">座標のポインタ</param>
/// <param name="_offset">オフセット</param>
/// <param name="_vel">速度のポインタ</param>
/// <param name="_width">横幅</param>
/// <param name="_height">縦幅</param>
RectCollider::RectCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float _width, const float _height) 
	: Collider(COLLIDER_TYPE_RECT)
	, pos(_pos)
	, offset(_offset)
	, vel(_vel)
	, width(_width)
	, height(_height) {
	
}

RectCollider::RectCollider(Vector2 * _pos, const Vector2 & _offset, Vector2 * _vel, const float _width, const float _height, const COLLIDER_TYPE _type)
	: Collider(_type)
	, pos(_pos)
	, offset(_offset)
	, vel(_vel)
	, width(_width)
	, height(_height) {
}

RectRotateCollider::RectRotateCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float _width, const float _height, float *_angle)
	: RectCollider(_pos, _offset, _vel, _width, _height, COLLIDER_TYPE_RECT_ROTATE)
	, angle(_angle) {

}


CircleCollider::CircleCollider(Vector2 *_pos, const Vector2 &_offset, Vector2 *_vel, const float _radius) 
	: Collider(COLLIDER_TYPE_CIRCLE)
	, pos(_pos)
	, offset(_offset)
	, vel(_vel)
	, radius(_radius) {

}

