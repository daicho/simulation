#include <stdio.h>

#define h 0.5
#define step 5
#define y1_0 4
#define y2_0 6

double y1p(double);
double v2p(double, double);
double y1(int);
double y2(int);

// y1'
double y1p(double y1) {
	return -0.5 * y1;
}

// v2'
double y2p(double y1, double y2) {
	return 4 - 0.1 * y1 - 0.3 * y2;
}

// y1_i
double y1(int i) {
    if (i)
        return y1(i - 1) + h * y1p(y1(i - 1));
    else
        return y1_0;
}

// y2_i
double y2(int i) {
    if (i)
        return y2(i - 1) + h * y2p(y1(i - 1), y2(i - 1));
    else
        return y2_0;
}

int main(void) {
    int i;

    for (i = 0; i <= step; i++)
        printf("y1_%d = %f, y2_%d = %f\n", i, y1(i), i, y2(i));

    return 0;
}
