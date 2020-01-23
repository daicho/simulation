#include <stdio.h>
#include <math.h>

#define R 1
#define C 0.3
#define L 10
#define t_0 0
#define Q_0 10
#define I_0 0

#define H 0.1
#define STEP 10

double Qp(double);
double Ip(double, double);
void heun(double *, double *, double *, double, int);

int main(void) {
    int i;
    double t[STEP + 1];
    double y[STEP + 1];
    double v[STEP + 1];

	heun(t, y, v, H, STEP);

    for (i = 0; i <= STEP; i++)
        printf("i = %2d, t = %.16f, y = %.16f, v = %.16f\n", i, t[i], y[i], v[i]);

    return 0;
}

// Q'
double Qp(double I) {
	return I;
}

// I'
double Ip(double Q, double I) {
	return (-R * I - Q / C) / L;
}

// ホイン法
void heun(double *t, double *Q, double *I, double h, int step) {
	int i;

	t[0] = t_0;
	Q[0] = Q_0;
	I[0] = I_0;

	for (i = 0; i <= step - 1; i++) {
		double k1;
		double k2;

		t[i + 1] = t[i] + h;

		k1 = h * Qp(I[i]);
		k2 = h * Qp(I[i] + k1);
		Q[i + 1] = Q[i] + (k1 + k2) / 2;

		k1 = h * Ip(Q[i], I[i]);
		k2 = h * Ip(Q[i] + h, I[i] + k1);
		I[i + 1] = I[i] + (k1 + k2) / 2;
	}
}
