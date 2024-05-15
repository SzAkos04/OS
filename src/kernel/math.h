#pragma once

#define TERMS 64

#define NAN (0.0 / 0.0)
#define INFINITY (1.0 / 0.0)

#define M_E 2.7182818284590452354
#define M_PI 3.14159265358979323846

#define M_EPSILON 1.0e-10

double acos(double x);
double acosh(double x);
double asin(double x);
double atan(double x);
double atan2(double y, double x);
double atanh(double x);
double cbrt(double x);
double ceil(double x);
double cos(double x);
double cosh(double x);
double exp(double x);
double fabs(double x);
double floor(double x);
double hypot(double x, double y);
double log(double x);
double log10(double x);
double pow(double x, double y);
double sin(double x);
double sinh(double x);
double sqrt(double x);
double tan(double x);
double tanh(double x);

int abs(int x);
int round(double x);
