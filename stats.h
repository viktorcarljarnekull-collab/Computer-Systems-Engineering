#ifndef STATS_H
#define STATS_H

#include "complex.h"

/*
 * Statistics of the magnitudes of an array of complex numbers.
 * n is the number of elements. Each function returns a double.
 *
 * variance_magnitude is the population variance:
 * (1/n) * sum((|z_i| - mean)^2)
 * The whole vector is the data set, so the divisor is n.
 */

double average_magnitude(const complex z[], int n);
double minimum_magnitude(const complex z[], int n);
double maximum_magnitude(const complex z[], int n);
double variance_magnitude(const complex z[], int n);

#endif
