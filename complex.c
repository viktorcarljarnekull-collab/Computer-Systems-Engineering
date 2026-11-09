#include "complex.h"

#include <math.h>

complex complex_conjugate(complex z)
{
    complex result;

    result.real = z.real;
    result.imag = -z.imag;
    return result;
}

complex complex_add(complex z1, complex z2)
{
    complex result;

    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

complex complex_sub(complex z1, complex z2)
{
    complex result;

    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

complex complex_mul(complex z1, complex z2)
{
    complex result;

    /* (a + bi)(c + di) = (ac - bd) + (ad + bc)i */
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z1.imag * z2.real;
    return result;
}

complex complex_div(complex z1, complex z2)
{
    complex result;
    double denom;

    /* (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2) */
    denom = z2.real * z2.real + z2.imag * z2.imag;
    result.real = (z1.real * z2.real + z1.imag * z2.imag) / denom;
    result.imag = (z1.imag * z2.real - z1.real * z2.imag) / denom;
    return result;
}

complex complex_reciprocal(complex z)
{
    complex result;
    double denom;

    /* 1 / (a + bi) = a / (a^2 + b^2) - b / (a^2 + b^2) i */
    denom = z.real * z.real + z.imag * z.imag;
    result.real = z.real / denom;
    result.imag = -z.imag / denom;
    return result;
}

double complex_magnitude(complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}
