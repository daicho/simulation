#include <stdio.h>
#include <math.h>

#define q_m 2
#define B 1
#define Ez 1

#define t0 0
#define x0 0
#define y0 0
#define z0 0
#define vx0 1
#define vy0 1
#define vz0 1

#define h 0.01
#define STEP 100

double xp(double);
double yp(double);
double zp(double);
double vxp(double);
double vyp(double);
double vzp();

int main(void) {
    int i;
    double t[STEP + 1];
    double x[STEP + 1];
    double vx[STEP + 1];
    double y[STEP + 1];
    double vy[STEP + 1];
    double z[STEP + 1];
    double vz[STEP + 1];

	t[0] = t0;
	x[0] = x0;
	vx[0] = vx0;
	y[0] = y0;
	vy[0] = vy0;
	z[0] = z0;
	vz[0] = vz0;

	for (i = 0; i <= STEP - 1; i++) {
		double k1;;
		double k2;

		t[i + 1] = t[i] + h;

		k1 = h * xp(vx[i]);
		k2 = h * xp(vx[i] + k1);
		x[i + 1] = x[i] + (k1 + k2) / 2;

		k1 = h * vxp(vy[i]);
		k2 = h * vxp(vy[i] + k1);
		vx[i + 1] = vx[i] + (k1 + k2) / 2;

		k1 = h * yp(vy[i]);
		k2 = h * yp(vy[i] + k1);
		y[i + 1] = y[i] + (k1 + k2) / 2;

		k1 = h * vyp(vx[i]);
		k2 = h * vyp(vx[i] + k1);
		vy[i + 1] = vy[i] + (k1 + k2) / 2;

		k1 = h * zp(vz[i]);
		k2 = h * zp(vz[i] + k1);
		z[i + 1] = z[i] + (k1 + k2) / 2;

		k1 = h * vzp();
		k2 = h * vzp();
		vz[i + 1] = vz[i] + (k1 + k2) / 2;
	}

	for (i = 0; i <= STEP; i++) {
		printf("t = %2.2f, x = (%8.5f, %8.5f, %8.5f), v = (%8.5f, %8.5f, %8.5f)\n", t[i], x[i], y[i], z[i], vx[i], vy[i], vz[i]);
	}

    return 0;
}

// x'
double xp(double vx) {
    return vx;
}

// vx'
double vxp(double vy) {
	return q_m * vy * B;
}

// y'
double yp(double vy) {
    return vy;
}

// vy'
double vyp(double vx) {
	return q_m * -vx * B;
}

// z'
double zp(double vz) {
    return vz;
}

// vz'
double vzp() {
	return q_m * Ez;
}
