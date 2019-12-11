#include <stdio.h>
#include <math.h>

#define x0 0.0
#define y0 0.5
#define STEP 10

double yp(double, double);
double ys(double);
void euler(double *, double *, double, int);

int main(void) {
    int i;
    double x[STEP + 1];
    double y[STEP + 1];

	euler(x, y, 0.5, STEP);

    for (i = 0; i <= STEP; i++)
        printf("i = %2d, x = %2.16f, y = %2.16f, e = %2.16f\n", i, x[i], y[i], y[i] - ys(x[i]));

    return 0;
}

// y'(x, y)
double yp(double x, double y) {
    return 2 * y / (1 + x);
}

// yの解析解
double ys(double x) {
    return 0.5 * (1 + x) * (1 + x);
}

// オイラー法
void euler(double *x, double *y, double h, int step) {
	int i;

	x[0] = x0;
	y[0] = y0;

	for (i = 0; i <= step - 1; i++) {
		x[i + 1] = x[i] + h;
		y[i + 1] = y[i] + h * yp(x[i], y[i]);
	}
}
