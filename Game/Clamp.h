#pragma once

#include <assert.h>


template <class T> T ClampT(T num, const T min, const T max) {
	assert(min < max);
	if (num < min) {
		return min;
	}
	else if (num > max) {
		return max;
	}
	return num;
}

