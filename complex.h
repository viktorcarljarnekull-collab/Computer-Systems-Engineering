#ifndef COMPLEX_H
#define COMPLEX_H

/*
 * A complex number a + b i.
 * real is a, imag is b. Both are real numbers (double).
 */
typedef struct {
    double real;
    double imag;
} complex;

/* Conjugate of z = a + b i is a - b i. */
complex complex_conjugate(complex z);

/* z1 + z2, z1 - z2, z1 * z2, z1 / z2. */
complex complex_add(complex z1, complex z2);
complex complex_sub(complex z1, complex z2);
complex complex_mul(complex z1, complex z2);
complex complex_div(complex z1, complex z2);

/* 1 / z. */
complex complex_reciprocal(complex z);

/* Magnitude r = sqrt(a^2 + b^2). This is a real number. */
double complex_magnitude(complex z);

#endif
