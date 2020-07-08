#include <math.h>

#include "vector.h"


struct Vector VEC_N = {0, -1};
struct Vector VEC_S = {0, 1};
struct Vector VEC_E = {1, 0};
struct Vector VEC_W = {-1, 0};
struct Vector VEC_NE = {1 / sqrt(2), -1 / sqrt(2)};
struct Vector VEC_NW = {-1 / sqrt(2), -1 / sqrt(2)};
struct Vector VEC_SE = {1 / sqrt(2), 1 / sqrt(2)};
struct Vector VEC_SW = {-1 / sqrt(2), 1 / sqrt(2)};
struct Vector ZERO = {0, 0};




struct Vector normalize(struct Vector v)
{
	double magnitude = sqrt(v.x*v.x + v.y*v.y);
	if (magnitude != 0)
		return scale(v, 1 / magnitude);
	else
		return ZERO;
}

struct Vector scale(struct Vector v, double scalar)
{
	struct Vector w = {v.x * scalar, v.y * scalar};
	return w;
}

struct Vector add(struct Vector u, struct Vector v)
{
	struct Vector w = {u.x + v.x, u.y + v.y};
	return w;
}

struct Vector subtract(struct Vector u, struct Vector v)
{
	struct Vector w = {u.x - v.x, u.y - v.y};
	return w;
}

double gaussian(double x, double a)
{
	return exp(-a * x * x);
}
