#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define p 0.5
#define L 1.0
#define N 100

double average(double *a) {
    int i;
    double sum = 0;

    for (i = 1; i <= N; i++)
        sum += a[i];

    return sum / N;
}

double bunsan(double *x, double *y) {
    int i;
    double sum = 0;
    double ave_x = average(x);
    double ave_y = average(y);

    for (i = 1; i <= N; i++)
        sum += (x[i] - ave_x) * (y[i] - ave_y);

    return sum / N;
}

int main(void) {
    int i;
    double x[N + 1] = {0};

    srand(time(NULL));

    for (i = 1; i <= N; i++) {
        if ((double)rand() / RAND_MAX < p)
            x[i] = x[i - 1] + L;
        else
            x[i] = x[i - 1] - L;
    }
    
    printf("x = %.1f\n", x[N]);
    printf("分散 = %.2f\n", bunsan(x, x));

    return 0;
}
