#include "Vec2df32.h"
#include <math.h>

/*****************************************************************************
Vec2df32_t addVec(const Vec2df32_t _First, const Vec2df32_t _Second)
	Description :
		Adds two given vectors.
	Parameters : 
		const Vec2df32_t _First: First vector. 
		const Vec2df32_t _Second: Second vector.
	Returns :
		Vector-sum of the given two vectors.
*****************************************************************************/
Vec2ds16_t addVec(const Vec2ds16_t _First, const Vec2ds16_t _Second)
{
	Vec2ds16_t vec = { _First.iX + _Second.iX, _First.iY + _Second.iY };
	return vec;
}

/*****************************************************************************
Vec2df32_t subVec(const Vec2df32_t _First, const Vec2df32_t _Second)
	Description :
		Subtracts two given vectors.
	Parameters : 
		const Vec2df32_t _First: First vector. 
		const Vec2df32_t _Second: Second vector.
	Returns :
		Vector-difference of the given two vectors.
*****************************************************************************/
Vec2ds16_t subVec(const Vec2ds16_t _First, const Vec2ds16_t _Second)
{
	Vec2ds16_t vec = { _First.iX - _Second.iX, _First.iY - _Second.iY };
	return vec;
}

/*****************************************************************************
Vec2df32_t mulVec(const Vec2df32_t _First, const Vec2df32_t _Second)
	Description :
		Multiplies two given vectors.
	Parameters : 
		const Vec2df32_t _First: First vector. 
		const Vec2df32_t _Second: Second vector.
	Returns :
		Vector-product of the given two vectors.
*****************************************************************************/
Vec2ds16_t mulVec(const Vec2ds16_t _First, const Vec2ds16_t _Second)
{
	Vec2ds16_t vec = { _First.iX * _Second.iX, _First.iY * _Second.iY };
	return vec;
}

/*****************************************************************************
Vec2df32_t divVec(const Vec2df32_t _First, const Vec2df32_t _Second)
	Description :
		Divides two given vectors.
	Parameters : 
		const Vec2df32_t _First: First vector. 
		const Vec2df32_t _Second: Second vector.
	Returns :
		Vector-quotient of the given two vectors.
*****************************************************************************/
Vec2ds16_t divVec(const Vec2ds16_t _First, const Vec2ds16_t _Second)
{
	Vec2ds16_t vec = { _First.iX / _Second.iX, _First.iY / _Second.iY };
	return vec;
}

/*****************************************************************************
Vec2df32_t normalize(const Vec2df32_t _First)
	Description :
		Normalizes the given vector.
	Parameters : 
		const Vec2df32_t _First: First vector. 
	Returns :
		Normalized vector.
*****************************************************************************/
Vec2ds16_t normalize(const Vec2ds16_t _First)
{
	float fFactor = sqrtf(_First.iX * _First.iX + _First.iY * _First.iY);
	Vec2ds16_t vec = { _First.iX / fFactor, _First.iY / fFactor };

	return vec;
}

/*****************************************************************************
float dotProduct(const Vec2df32_t _First, const Vec2df32_t _Second)
	Description :
		Calculates the dot product of the two given vectors.
	Parameters : 
		const Vec2df32_t _First: First vector. 
		const Vec2df32_t _Second: Second vector.
	Returns :
		Dot product of the two given vectors.
*****************************************************************************/
float dotProduct(const Vec2ds16_t _First, const Vec2ds16_t _Second)
{
	return (_First.iX * _Second.iX + _First.iY * _Second.iY);
}

/*****************************************************************************
Vec2df32_t crossProduct(const Vec2df32_t _First)
	Description :
		Calculates the cross product of the given vector.
	Parameters : 
		const Vec2df32_t _First: First vector. 
	Returns :
		Cross product of the given vector.
*****************************************************************************/
Vec2ds16_t crossProduct(const Vec2ds16_t _First)
{
	Vec2ds16_t vec = { _First.iY, -_First.iX };
	return vec;
}
