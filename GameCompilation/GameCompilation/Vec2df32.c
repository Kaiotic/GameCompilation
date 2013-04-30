#include "Vec2df32.h"
#include <math.h>

Vec2df32_t addVec(const Vec2df32_t _First, const Vec2df32_t _Second)
{
  Vec2df32_t vec = { _First.iX + _Second.iX, _First.iY + _Second.iY };
	return vec;
}

Vec2df32_t subVec(const Vec2df32_t _First, const Vec2df32_t _Second)
{
	Vec2df32_t vec = { _First.iX - _Second.iX, _First.iY - _Second.iY };
	return vec;
}

Vec2df32_t mulVec(const Vec2df32_t _First, const Vec2df32_t _Second)
{
	Vec2df32_t vec = { _First.iX * _Second.iX, _First.iY * _Second.iY };
	return vec;
}

Vec2df32_t divVec(const Vec2df32_t _First, const Vec2df32_t _Second)
{
	Vec2df32_t vec = { _First.iX / _Second.iX, _First.iY / _Second.iY };
	return vec;
}

Vec2df32_t normalize(const Vec2df32_t _First)
{
	float fFactor = sqrtf(_First.iX * _First.iX + _First.iY * _First.iY);
	Vec2df32_t vec = { _First.iX / fFactor, _First.iY / fFactor };

	return vec;
}

float dotProduct(const Vec2df32_t _First, const Vec2df32_t _Second)
{
	return (_First.iX * _Second.iX + _First.iY * _Second.iY);
}

Vec2df32_t crossProduct(const Vec2df32_t _First)
{
	Vec2df32_t vec = { -(_First.iY), _First.iX };
	return vec;
}
