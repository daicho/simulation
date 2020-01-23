#include <stdio.h>
#include <math.h>

#define l 3
#define k 2
#define m 1
#define t_0 0
#define y_0 10
#define v_0 0

#define H 0.1
#define STEP 10

double yp(double);
double vp(double, double);
void euler(double *, double *, double *, double, int);

int main(void) {
    int i;
    double t[STEP + 1];
    double y[STEP + 1];
    double v[STEP + 1];

	euler(t, y, v, H, STEP);

    for (i = 0; i <= STEP; i++)
        printf("i = %2d, t = %.16f, y = %.16f, v = %.16f\n", i, t[i], y[i], v[i]);

    return 0;
}

// y'
double yp(double v) {
	return v;
}

// v'
double vp(double y, double v) {
	return (-k * y - l * v) / m;
}

// オイラー法
void euler(double *t, double *y, double *v, double h, int step) {
	int i;

    t[0] = t_0;
	y[0] = y_0;
	v[0] = v_0;

	for (i = 0; i <= step - 1; i++) {
		t[i + 1] = t[i] + h;
		y[i + 1] = y[i] + h * yp(v[i]);
		v[i + 1] = v[i] + h * vp(y[i], v[i]);
	}
}
