#include <stdio.h>
#include <math.h>

/* Question 1. One complex number is a + bi. */

typedef struct {
    double real;
    double imag;
} complex;

complex conjugate(complex z)
{
    complex result;

    result.real = z.real;
    result.imag = -z.imag;
    return result;
}

complex add(complex z1, complex z2)
{
    complex result;

    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

complex sub(complex z1, complex z2)
{
    complex result;

    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

complex mul(complex z1, complex z2)
{
    complex result;

    /* (a + bi)(c + di) = (ac - bd) + (ad + bc)i */
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z1.imag * z2.real;
    return result;
}

complex divide(complex z1, complex z2)
{
    complex result;
    double denom;

    /* (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2) */
    denom = z2.real * z2.real + z2.imag * z2.imag;
    result.real = (z1.real * z2.real + z1.imag * z2.imag) / denom;
    result.imag = (z1.imag * z2.real - z1.real * z2.imag) / denom;
    return result;
}

complex reciprocal(complex z)
{
    complex result;
    double denom;

    /* 1 / (a + bi) = a/(a^2 + b^2) - b/(a^2 + b^2) i */
    denom = z.real * z.real + z.imag * z.imag;
    result.real = z.real / denom;
    result.imag = -z.imag / denom;
    return result;
}

double magnitude(complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}

static void print_complex(const char *label, complex z)
{
    if (z.imag < 0.0) {
        printf("%s = %.6f - %.6fi\n", label, z.real, -z.imag);
    } else {
        printf("%s = %.6f + %.6fi\n", label, z.real, z.imag);
    }
}

int main(void)
{
    complex z1;
    complex z2;

    printf("Enter four real numbers: Re(z1) Im(z1) Re(z2) Im(z2)\n");
    if (scanf("%lf %lf %lf %lf",
              &z1.real, &z1.imag, &z2.real, &z2.imag) != 4) {
        fprintf(stderr, "Expected four real numbers.\n");
        return 1;
    }

    print_complex("z1", z1);
    print_complex("z2", z2);
    print_complex("conjugate of z1", conjugate(z1));
    print_complex("z1 + z2", add(z1, z2));
    print_complex("z1 - z2", sub(z1, z2));
    print_complex("z1 * z2", mul(z1, z2));
    print_complex("z1 / z2", divide(z1, z2));
    printf("|z1| = %.6f\n", magnitude(z1));
    print_complex("1/z1", reciprocal(z1));

    return 0;
}
