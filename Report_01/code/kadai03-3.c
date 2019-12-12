#include <stdio.h>
#include <math.h>

#define t0 0.0
#define u0 1.0
#define STEP 10

double up(double, double);
double us(double);
void euler(double *, double *, double, int);
void heun(double *, double *, double, int);
void runge_kutta(double *, double *, double, int);

int main(void) {
    int i;
    double t[STEP + 1];
    double u[STEP + 1];

	euler(t, u, 0.1, STEP);

    printf("オイラー法\n");
    for (i = 0; i <= STEP; i++)
        printf("i = %2d, t = %.16f, u = %.16f, e = %.16f\n", i, t[i], u[i], u[i] - us(t[i]));
	printf("\n");

	heun(t, u, 0.1, STEP);

    printf("ホイン法\n");
    for (i = 0; i <= STEP; i++)
        printf("i = %2d, t = %.16f, u = %.16f, e = %.16f\n", i, t[i], u[i], u[i] - us(t[i]));
	printf("\n");

	runge_kutta(t, u, 0.1, STEP);

    printf("ルンゲ・クッタ法\n");
    for (i = 0; i <= STEP; i++)
        printf("i = %2d, t = %.16f, u = %.16f, e = %.16f\n", i, t[i], u[i], u[i] - us(t[i]));

    return 0;
}

// u'(t, u)
double up(double t, double u) {
    return u;
}

// uの解析解
double us(double t) {
    return exp(t);
}

// オイラー法
void euler(double *t, double *u, double h, int step) {
	int i;

	t[0] = t0;
	u[0] = u0;

	for (i = 0; i <= step - 1; i++) {
		t[i + 1] = t[i] + h;
		u[i + 1] = u[i] + h * up(t[i], u[i]);
	}
}

// ホイン法
void heun(double *t, double *u, double h, int step) {
	int i;

	t[0] = t0;
	u[0] = u0;

	for (i = 0; i <= step - 1; i++) {
		double k1 = h * up(t[i], u[i]);
		double k2 = h * up(t[i] + h, u[i] + k1);

		t[i + 1] = t[i] + h;
		u[i + 1] = u[i] + (k1 + k2) / 2;
	}
}

// ルンゲ・クッタ法
void runge_kutta(double *t, double *u, double h, int step) {
	int i;

	t[0] = t0;
	u[0] = u0;

	for (i = 0; i <= step - 1; i++) {
		double k1 = h * up(t[i], u[i]);
		double k2 = h * up(t[i] + h / 2, u[i] + k1 / 2);
		double k3 = h * up(t[i] + h / 2, u[i] + k2 / 2);
		double k4 = h * up(t[i] + h, u[i] + k3);

		t[i + 1] = t[i] + h;
		u[i + 1] = u[i] + (k1 + k2 * 2 + k3 * 2 + k4) / 6;
	}
}
