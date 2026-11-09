#include "stats.h"

double average_magnitude(const complex z[], int n)
{
    double sum;
    int i;

    if (n <= 0) {
        return 0.0;
    }

    sum = 0.0;
    for (i = 0; i < n; i++) {
        sum += complex_magnitude(z[i]);
    }
    return sum / (double)n;
}

double minimum_magnitude(const complex z[], int n)
{
    double min_mag;
    int i;

    if (n <= 0) {
        return 0.0;
    }

    min_mag = complex_magnitude(z[0]);
    for (i = 1; i < n; i++) {
        double mag = complex_magnitude(z[i]);
        if (mag < min_mag) {
            min_mag = mag;
        }
    }
    return min_mag;
}

double maximum_magnitude(const complex z[], int n)
{
    double max_mag;
    int i;

    if (n <= 0) {
        return 0.0;
    }

    max_mag = complex_magnitude(z[0]);
    for (i = 1; i < n; i++) {
        double mag = complex_magnitude(z[i]);
        if (mag > max_mag) {
            max_mag = mag;
        }
    }
    return max_mag;
}

double variance_magnitude(const complex z[], int n)
{
    double mean;
    double sum_sq;
    int i;

    if (n <= 0) {
        return 0.0;
    }

    mean = average_magnitude(z, n);
    sum_sq = 0.0;
    for (i = 0; i < n; i++) {
        double delta = complex_magnitude(z[i]) - mean;
        sum_sq += delta * delta;
    }
    return sum_sq / (double)n;
}
