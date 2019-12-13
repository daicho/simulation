#include <stdio.h>

#define h 0.5
#define step 20
#define l 3
#define k 2
#define m 1
#define y_0 0
#define v_0 10

double yp(double);
double vp(double, double);
double y(int);
double v(int);

// y'
double yp(double v) {
	return v;
}

// v'
double vp(double y, double v) {
	return (-k * y - l * v) / m;
}

// y_i
double y(int i) {
    if (i)
        return y(i - 1) + h * yp(v(i - 1));
    else
        return y_0;
}

// v_i
double v(int i) {
    if (i)
        return v(i - 1) + h * vp(y(i - 1), v(i - 1));
    else
        return v_0;
}

int main(void) {
    int i;

    for (i = 1; i <= step; i++)
        printf("y_%d = %f, v_%d = %f\n", i, y(i), i, v(i));

    return 0;
}
