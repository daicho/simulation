#include <stdio.h>
#include <math.h>

#define a 0.0
#define b 1.0
#define SOLUTION M_PI

double f(double);
double trapezoid(int);

int main(void) {
    int i;

    for (i = 1; i <= 32; i *= 2) {
        double S = trapezoid(i);
        printf("n = %2d, S = %.16f, e = %.16f\n", i, S, S - SOLUTION);
    }

    return 0;
}

// f(x)
double f(double x) {
    return 4.0 / (1.0 + x * x);
}

// ‘äŒ`ŒöŽ®
double trapezoid(int n) {
    int i;
    double x;
    double h = (b - a) / n;
    double S = f(a) + f(b);

    for (i = 1; i <= n - 1; i++) {
        x = a + i * h;
        S += f(x) * 2;
    }

    S = S * h / 2;
    return S;
}
