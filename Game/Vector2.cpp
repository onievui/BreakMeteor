#include "Vector2.h"
#include <iostream>

using namespace std;


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