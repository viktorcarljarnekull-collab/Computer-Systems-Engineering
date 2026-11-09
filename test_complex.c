#include "complex.h"
#include "stats.h"

#include <math.h>
#include <stdio.h>

static int g_failures = 0;

static int nearly_equal(double a, double b)
{
    double diff = fabs(a - b);
    double scale = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    if (scale < 1.0) {
        scale = 1.0;
    }
    return diff <= 1e-9 * scale;
}

static void expect_real(const char *name, double got, double want)
{
    if (!nearly_equal(got, want)) {
        printf("FAIL %s: got %.12g, want %.12g\n", name, got, want);
        g_failures++;
    }
}

static void expect_complex(const char *name, complex got, double re, double im)
{
    if (!nearly_equal(got.real, re) || !nearly_equal(got.imag, im)) {
        printf("FAIL %s: got %.12g + %.12gi, want %.12g + %.12gi\n",
               name, got.real, got.imag, re, im);
        g_failures++;
    }
}

static void test_arithmetic(void)
{
    complex z1;
    complex z2;

    z1.real = 3.0;
    z1.imag = 4.0;
    z2.real = 1.0;
    z2.imag = -2.0;

    expect_complex("conjugate", complex_conjugate(z1), 3.0, -4.0);
    expect_complex("add", complex_add(z1, z2), 4.0, 2.0);
    expect_complex("sub", complex_sub(z1, z2), 2.0, 6.0);
    expect_complex("mul", complex_mul(z1, z2), 11.0, -2.0);
    /* (3+4i)/(1-2i) = -1 + 2i */
    expect_complex("div", complex_div(z1, z2), -1.0, 2.0);
    expect_complex("div*z2", complex_mul(complex_div(z1, z2), z2), 3.0, 4.0);
    expect_complex("reciprocal", complex_reciprocal(z1), 0.12, -0.16);
    expect_real("magnitude", complex_magnitude(z1), 5.0);

    /* (1/z) * z == 1 */
    expect_complex("reciprocal*z",
                   complex_mul(complex_reciprocal(z1), z1), 1.0, 0.0);
}

static void test_stats(void)
{
    complex z[3];

    z[0].real = 3.0;
    z[0].imag = 4.0;   /* magnitude 5 */
    z[1].real = 0.0;
    z[1].imag = 0.0;   /* magnitude 0 */
    z[2].real = 5.0;
    z[2].imag = 12.0;  /* magnitude 13 */

    expect_real("average", average_magnitude(z, 3), 6.0);
    expect_real("minimum", minimum_magnitude(z, 3), 0.0);
    expect_real("maximum", maximum_magnitude(z, 3), 13.0);
    expect_real("variance", variance_magnitude(z, 3), 86.0 / 3.0);

    expect_real("empty average", average_magnitude(z, 0), 0.0);
    expect_real("empty minimum", minimum_magnitude(z, 0), 0.0);
    expect_real("empty maximum", maximum_magnitude(z, 0), 0.0);
    expect_real("empty variance", variance_magnitude(z, 0), 0.0);
}

int main(void)
{
    test_arithmetic();
    test_stats();

    if (g_failures != 0) {
        printf("%d check(s) failed\n", g_failures);
        return 1;
    }
    printf("all checks passed\n");
    return 0;
}
