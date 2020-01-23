#include <stdio.h>
#include <math.h>

#define a 1
#define b 1
#define c 1
#define d 1
#define x_0 0.0
#define y1_0 10
#define y2_0 10

#define H 0.1
#define STEP 10

double y1p(double, double);
double y2p(double, double);
void euler(double *, double *, double *, double, int);

int main(void) {
    int i;
    double x[STEP + 1];
    double y1[STEP + 1];
    double y2[STEP + 1];

	euler(x, y1, y2, H, STEP);

    for (i = 0; i <= STEP; i++)
        printf("i = %2d, x = %.16f, y1 = %.16f, y2 = %.16f\n", i, x[i], y1[i], y2[i]);

    return 0;
}

// y1'(y1, y2)
double y1p(double y1, double y2) {
    return a * y1 - c * y1 * y2;
}

// y2'(y1, y2)
double y2p(double y1, double y2) {
    return -b * y2 + d * y1 * y2;
}

// オイラー法
void euler(double *x, double *y1, double *y2, double h, int step) {
	int i;

    x[0] = x_0;
	y1[0] = y1_0;
	y2[0] = y2_0;

	for (i = 0; i <= step - 1; i++) {
		x[i + 1] = x[i] + h;
		y1[i + 1] = y1[i] + h * y1p(y1[i], y2[i]);
		y2[i + 1] = y2[i] + h * y2p(y1[i], y2[i]);
	}
}
