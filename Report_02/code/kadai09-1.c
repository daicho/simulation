#include <stdio.h>
#include <math.h>

#define qB_m 2
#define t0 0
#define x0 0
#define v0 1

#define H 0.01
#define STEP 100

double xp(double, double);
double vp(double, double);
double xs(double);
double vs(double);
void heun(double *, double *, double *, double, int);

int main(void) {
    int i;
    double t[STEP + 1];
    double x[STEP + 1];
    double v[STEP + 1];

	heun(t, x, v, H, STEP);

    printf("オイラー法\n");
    for (i = 0; i <= STEP; i++) {
        printf("i = %2d, t = %.16f, x = %.16f, v = %.16f\n", i, t[i], x[i], v[i]);
    	printf("e_x = %.16f, e_y = %.16f\n", x[i] - xs(t[i]), v[i] - vs(t[i]));
    	printf("\n");
    }

    return 0;
}

// x'(x, v)
double xp(double x, double v) {
    return v;
}

// v'(x, v)
double vp(double x, double v) {
	return qB_m * v;
}

// xの解析解
double xs(double t) {
	return (exp(qB_m * t) - 1) / qB_m;
}

// vの解析解
double vs(double t) {
	return exp(qB_m * t);
}

// ホイン法
void heun(double *t, double *x, double *v, double h, int step) {
	int i;

	t[0] = t0;
	x[0] = x0;
	v[0] = v0;

	for (i = 0; i <= step - 1; i++) {
		double k1;;
		double k2;

		t[i + 1] = t[i] + h;

		k1 = h * xp(x[i], v[i]);
		k2 = h * xp(x[i] + h, v[i] + k1);
		x[i + 1] = x[i] + (k1 + k2) / 2;

		k1 = h * vp(x[i], v[i]);
		k2 = h * vp(x[i] + h, v[i] + k1);
		v[i + 1] = v[i] + (k1 + k2) / 2;
	}
}
