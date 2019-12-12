#include <stdio.h>
#include <math.h>

#define a 0.0
#define b (M_PI / 2)
#define SOLUTION 1

double f(double);
double simpson(int);

int main(void) {
    int i;

    for (i = 2; i <= 32; i *= 2) {
        double S = simpson(i);
        printf("n = %2d, S = %.16f, e = %.16f\n", i, S, S - SOLUTION);
    }

    return 0;
}

// f(x)
double f(double x) {
    return sin(x);
}

// ƒVƒ“ƒvƒ\ƒ“‚ÌŒöŽ®
double simpson(int n) {
    int i;
    double x;
    double h = (b - a) / n;
    double S = f(a) + f(b);

    for (i = 1; i <= n - 1; i += 2) {
        x = a + i * h;
        S += f(x) * 4;
    }

    for (i = 2; i <= n - 2; i += 2) {
        x = a + i * h;
        S += f(x) * 2;
    }

    S = S * h / 3;
    return S;
}
