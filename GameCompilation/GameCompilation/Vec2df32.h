#ifndef VEC2DF32_H_INCLUDED
#define VEC2DF32_H_INCLUDED

typedef struct
{
	float iX;
	float iY;
} Vec2df32_t;

Vec2df32_t addVec(const Vec2df32_t _First, const Vec2df32_t _Second);
Vec2df32_t subVec(const Vec2df32_t _First, const Vec2df32_t _Second);
Vec2df32_t mulVec(const Vec2df32_t _First, const Vec2df32_t _Second);
Vec2df32_t divVec(const Vec2df32_t _First, const Vec2df32_t _Second);

Vec2df32_t normalize(const Vec2df32_t _First);
float dotProduct(const Vec2df32_t _First, const Vec2df32_t _Second);
Vec2df32_t crossProduct(const Vec2df32_t _First);

#endif //VEC2DF32_H_INCLUDED
