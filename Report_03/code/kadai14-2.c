#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N    200
#define STEP 1000
#define P_x  0.5
#define P_y  0.5
#define L    1.0

void random_walk(double *, double *, int, double, double, double);

int main(void) {
    int i;
    double x[N] = {0};
    double y[N] = {0};

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        random_walk(&x[i], &y[i], STEP, P_x, P_y, L);
        printf("(%11f, %11f)\n", x[i], y[i]);
    }

    return 0;
}

// ランダムウォーク
void random_walk(double *x, double *y, int n, double p_x, double p_y, double l) {
    int i;

    for (i = 0; i < n; i++) {
        *x += ((double)rand() / RAND_MAX < p_x ? l : -l);
        *y += ((double)rand() / RAND_MAX < p_y ? l : -l);
    }
}
