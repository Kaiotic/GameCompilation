#ifndef VEC2DF32_H_INCLUDED
#define VEC2DF32_H_INCLUDED

typedef struct
{
	short iX;
	short iY;
} Vec2ds16_t;

Vec2ds16_t addVec(const Vec2ds16_t* _First, const Vec2ds16_t* _Second);
Vec2ds16_t subVec(const Vec2ds16_t* _First, const Vec2ds16_t* _Second);
Vec2ds16_t mulVec(const Vec2ds16_t* _First, const Vec2ds16_t* _Second);
Vec2ds16_t divVec(const Vec2ds16_t* _First, const Vec2ds16_t* _Second);

Vec2ds16_t normalize(const Vec2ds16_t* _First);
float dotProduct(const Vec2ds16_t* _First, const Vec2ds16_t* _Second);
Vec2ds16_t crossProduct(const Vec2ds16_t* _First);

#endif //VEC2DF32_H_INCLUDED
