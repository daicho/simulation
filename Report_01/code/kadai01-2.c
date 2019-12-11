#include <stdio.h>
#include <math.h>

#define a 0.0
#define b (M_PI / 6)

double f(double);
double sol();
double trapezoid(int);

int main(void) {
    int i;

    for (i = 1; i <= 32; i *= 2) {
        double S = trapezoid(i);
        printf("n = %2d, S = %2.16f, e = %2.16f\n", i, S, S - sol());
    }

    return 0;
}

// f(x)
double f(double x) {
    return 1 / cos(x);
}

// ‰ðÍ‰ð
double sol() {
    return log(3) / 2;
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
