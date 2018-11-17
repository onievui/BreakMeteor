#include "Vector2.h"
#include <iostream>

using namespace std;


float Vector2::distancePowPoint(const Vector2 &_pos1, const Vector2 &_pos2) {
	return (_pos1.x - _pos2.x)*(_pos1.x - _pos2.x) + (_pos1.y - _pos2.y)*(_pos1.y - _pos2.y);
}

Vector2 Vector2::createWithAngleNorm(const float _angle, const float _norm) {
	return { cos(_angle)*_norm,sin(_angle)*_norm };
}

Vector2 Vector2::clamp(const Vector2 &_vec, const Vector2 &_min, const Vector2 &_max) {
	Vector2 vec = _vec;

	if (vec.x < _min.x) {
		vec.x =_min.x;
	}
	else if (vec.x > _max.x) {
		vec.x = _max.x;
	}

	if (vec.y < _min.y) {
		vec.y = _min.y;
	}
	else if (vec.y > _max.y) {
		vec.y =_max.y;
	}

	return vec;
}

Vector2 Vector2::rotate(const Vector2 &_vec, const float _rad, const Vector2 &_center) {
	Vector2 vec;
	vec.x = (_vec.x - _center.x) * cosf(_rad) - (_vec.y - _center.y) * sinf(_rad) + _center.x;
	vec.y = (_vec.x - _center.x) * sinf(_rad) + (_vec.y - _center.y) * cosf(_rad) + _center.y;
	return vec;
}

