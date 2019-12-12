#include <stdio.h>
#include <math.h>

#define a 0.0
#define b (M_PI / 2)
#define SOLUTION 1

float f(float);
float simpson(int);

int main(void) {
    int i;

    for (i = 2; i <= 32; i *= 2) {
        float S = simpson(i);
        printf("n = %2d, S = %.16f, e = %.16f\n", i, S, S - SOLUTION);
    }

    return 0;
}

// f(x)
float f(float x) {
    return sin(x);
}

// ƒVƒ“ƒvƒ\ƒ“‚ÌŒöŽ®
float simpson(int n) {
    int i;
    float x;
    float h = (b - a) / n;
    float S = f(a) + f(b);

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
