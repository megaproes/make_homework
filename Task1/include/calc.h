#ifndef CALC_H
#define CALC_H

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);

/* return 0 ok, -1 error */
int divide(double a, double b, double *out);

/* 0 ok, -1 error */
int factorial(unsigned int n, unsigned long long *out);

/* 0 ok, -1 error  */
int square_root(double x, double *out);

#endif
