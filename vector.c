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


double magnitude(struct Vector v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

struct Vector normalize(struct Vector v)
{
	double m = magnitude(v);
	if (m != 0)
		return scale(v, 1 / m);
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

double dot_product(struct Vector u, struct Vector v)
{
	return u.x * v.x + u.y * v.y;
}

/* Project v onto b. */
struct Vector projection(struct Vector v, struct Vector b)
{
	struct Vector w = ZERO;
	w = normalize(b);
	w = scale(w, dot_product(v, b));

	return w;
}

double signum(double x)
{
	if (x == 0)
		return 0;
	else if (x > 0)
		return 1;
	else if (x < 0)
		return -1;
}

bool equal(struct Vector u, struct Vector v)
{
	return (u.x == v.x) && (u.y == v.y);
}
