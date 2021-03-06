#include <stdio.h>
#include <math.h>

#define qE 1
#define qB_m 1
#define t_0 0
#define x_0 0.1
#define y_0 0
#define z_0 0
#define vx_0 1
#define vy_0 0.1
#define vz_0 1

#define H 0.01
#define STEP 100

double xp(double);
double yp(double);
double vxp(double);
double vyp(double);
void heun(double *, double *, double *, double *, double *, double *, double *, double, int);

int main(void) {
    int i;
    double t[STEP + 1];
    double x[STEP + 1];
    double y[STEP + 1];
    double z[STEP + 1];
    double vx[STEP + 1];
    double vy[STEP + 1];
    double vz[STEP + 1];

	heun(t, x, y, z, vx, vy, vz, H, STEP);

    for (i = 0; i <= STEP; i++) {
        printf("t = %.2f, x = (%.6f, %.6f, %.6f), v = (%.6f, %.6f, %.6f)\n", t[i], x[i], y[i], z[i], vx[i], vy[i], vz[i]);
    }

    return 0;
}

// x'(vx)
double xp(double vx) {
    return vx;
}

// y'(vy)
double yp(double vy) {
    return vy;
}

// z'(vz)
double zp(double vz) {
    return qE * vz;
}

// vx'(vy)
double vxp(double vy) {
	return vy;
}

// vy'(vx)
double vyp(double vx) {
	return -qB_m * vx;
}

// vz'(vz)
double vzp(double vz) {
	return qE;
}

// ホイン法
void heun(double *t, double *x, double *y, double *z, double *vx, double *vy, double *vz, double h, int step) {
	int i;

	t[0] = t_0;
	x[0] = x_0;
	y[0] = y_0;
	z[0] = z_0;
	vx[0] = vx_0;
	vy[0] = vy_0;
	vz[0] = vz_0;

	for (i = 0; i <= step - 1; i++) {
		double k1;
		double k2;

		t[i + 1] = t[i] + h;

		k1 = h * xp(vx[i]);
		k2 = h * xp(vx[i] + k1);
		x[i + 1] = x[i] + (k1 + k2) / 2;

		k1 = h * yp(vy[i]);
		k2 = h * yp(vy[i] + k1);
		y[i + 1] = y[i] + (k1 + k2) / 2;

		k1 = h * zp(vz[i]);
		k2 = h * zp(vz[i] + k1);
		z[i + 1] = z[i] + (k1 + k2) / 2;

		k1 = h * vxp(vy[i]);
		k2 = h * vxp(vy[i] + k1);
		vx[i + 1] = vx[i] + (k1 + k2) / 2;

		k1 = h * vyp(vx[i]);
		k2 = h * vyp(vx[i] + k1);
		vy[i + 1] = vy[i] + (k1 + k2) / 2;

		k1 = h * zp(vz[i]);
		k2 = h * zp(vz[i] + k1);
		vz[i + 1] = vz[i] + (k1 + k2) / 2;
	}
}
