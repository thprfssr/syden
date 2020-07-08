#ifndef VECTOR_H
#define VECTOR_H


struct Vector {
	double x;
	double y;
};

extern struct Vector VEC_N;
extern struct Vector VEC_S;
extern struct Vector VEC_E;
extern struct Vector VEC_W;
extern struct Vector VEC_NE;
extern struct Vector VEC_NW;
extern struct Vector VEC_SE;
extern struct Vector VEC_SW;
extern struct Vector ZERO;


struct Vector normalize(struct Vector v);
struct Vector scale(struct Vector v, double scalar);
struct Vector add(struct Vector u, struct Vector v);
struct Vector subtract(struct Vector u, struct Vector v);
double gaussian(double x, double a);
double dot_product(struct Vector u, struct Vector v);


#endif
