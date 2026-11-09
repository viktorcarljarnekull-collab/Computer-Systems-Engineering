#include "complex.h"

#include <stdio.h>

/*
 * Question 1.
 * Read two complex numbers and print the sum, difference, product,
 * quotient, and the magnitude and reciprocal of z1.
 *
 * The handout says "outputs z1+z1". The operation defined in part 3
 * is z1+z2, and z2 would otherwise be unused by the sum, so this
 * program prints z1 + z2.
 */

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
    double z2_mag;

    printf("Enter four real numbers: Re(z1) Im(z1) Re(z2) Im(z2)\n");
    if (scanf("%lf %lf %lf %lf",
              &z1.real, &z1.imag, &z2.real, &z2.imag) != 4) {
        fprintf(stderr, "Expected four real numbers.\n");
        return 1;
    }

    print_complex("z1", z1);
    print_complex("z2", z2);
    print_complex("z1 + z2", complex_add(z1, z2));
    print_complex("z1 - z2", complex_sub(z1, z2));
    print_complex("z1 * z2", complex_mul(z1, z2));

    z2_mag = complex_magnitude(z2);
    if (z2_mag == 0.0) {
        printf("z1 / z2 = undefined (division by zero)\n");
    } else {
        print_complex("z1 / z2", complex_div(z1, z2));
    }

    printf("|z1| = %.6f\n", complex_magnitude(z1));

    if (complex_magnitude(z1) == 0.0) {
        printf("1/z1 = undefined (reciprocal of zero)\n");
    } else {
        print_complex("1/z1", complex_reciprocal(z1));
    }

    return 0;
}
