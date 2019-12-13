#include <stdio.h>

#define h 0.5
#define step 20
#define R 1
#define C 0.3
#define L 10
#define Q_0 10
#define I_0 0

double Qp(double);
double Ip(double, double);
double Q(int);
double I(int);

// Q'
double Qp(double I) {
	return I;
}

// I'
double Ip(double Q, double I) {
	return (-R * I - Q / C) / L;
}

// Q_i
double Q(int i) {
    if (i) {
        double k_1 = h * Qp(I(i - 1));
        double k_2 = h * Qp(I(i - 1) + k_1);
        return Q(i - 1) + (k_1 + k_2) / 2;
    } else {
        return Q_0;
    }
}

// I_i
double I(int i) {
    if (i) {
        double k_1 = h * Ip(Q(i - 1), I(i - 1));
        double k_2 = h * Ip(Q(i - 1) + h, I(i - 1) + k_1);
        return I(i - 1) + (k_1 + k_2) / 2;
    } else {
        return I_0;
    }
}

int main(void) {
    int i;

    for (i = 0; i <= step; i++)
        printf("Q_%d = %f, I_%d = %f\n", i, Q(i), i, I(i));

    return 0;
}
