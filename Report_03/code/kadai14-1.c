#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define p 0.5
#define L 1.0
#define N 100

double variace(double *);
void quadratic(double[N], double[N], double *, double *, double *);
void gauss(double[3][4]);

double variance(double *x) {
    int i;
    double sum = 0;
    double ave = 0;

    for (i = 1; i <= N; i++)
        ave += x[i];
    ave /= N;

    for (i = 1; i <= N; i++)
        sum += pow((x[i] - ave), 2);
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
    printf("V = %.2f\n", variance(x));

    return 0;
}
