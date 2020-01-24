#include <stdio.h>
#include <math.h>

#define N 4

double average(double *a) {
    int i;
    double sum = 0;

    for (i = 0; i < N; i++)
        sum += a[i];

    return sum / N;
}

int main(void) {
    int i;
    double a, b;
    double bunsan = 0, kyobunsan = 0;
    double x[N] = {1, 2, 3, 4};
    double y[N] = {0, 1, 2, 4};
    double ave_x = average(x), ave_y = average(y);

    for (i = 0; i < N; i++) {
        bunsan += pow(x[i] - ave_x, 2);
        kyobunsan += (x[i] - ave_x) * (y[i] - ave_y);
    }

    a = kyobunsan / bunsan;
    b = ave_y - a * ave_x;

    printf("y = %.3f + %.3f\n", a, b);

    return 0;
}
