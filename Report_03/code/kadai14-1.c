#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PLOT_N   50
#define DATA_N   100
#define STEP_MAX 5000

#define P 0.5
#define L 1.0

void random_walk(double[], int, double, double);
void linear(double[], double[], int, double *, double *);
void quadratic(double[], double[], int, double *, double *, double *);
void gauss(double[3][4]);
double variance(double[], int);
double covariance(double[], double[], int);
double average(double[], int);

int main(void) {
    int i, j;
    double a, b, c;
    int n[PLOT_N];
    double nd[PLOT_N];
    double x[STEP_MAX + 1] = {0};
    double V[PLOT_N];

    srand(time(NULL));

    // nを決定
    for (i = 0; i < PLOT_N; i++) {
        n[i] = (i + 1) * 100;
        nd[i] = (double)n[i];
    }

    // ランダムウォークの分散を記録
    for (i = 0; i < PLOT_N; i++) {
        double sum = 0;

        for (j = 0; j < DATA_N; j++) {
            random_walk(x, n[i], P, L);
            sum += variance(x + 1, n[i]);
        }

        V[i] = sum / DATA_N;
    }

    // 結果を出力
    for (i = 0; i < PLOT_N; i++)
        printf("(n, V) = (%4d, %11f)\n", n[i], V[i]);
    printf("\n");

    // 最小二乗法
    linear(nd, V, PLOT_N, &a, &b);
    printf("y = %fx + %f\n", a, b);

    quadratic(nd, V, PLOT_N, &a, &b, &c);
    printf("y = %fx^2 + %fx + %f\n", a, b, c);

    return 0;
}

// ランダムウォーク
void random_walk(double x[], int n, double p, double l) {
    int i;

    for (i = 0; i < n; i++)
        x[i + 1] = x[i] + ((double)rand() / RAND_MAX < p ? l : -l);
}

// 一次方程式による最小二乗法
void linear(double x[], double y[], int n, double *a, double *b) {
    double V_x = variance(x, n), V_xy = covariance(x, y, n);
    double ave_x = average(x, n), ave_y = average(y, n);

    *a = V_xy / V_x;
    *b = ave_y - *a * ave_x;
}

// 二次方程式による最小二乗法
void quadratic(double x[], double y[], int n, double *a, double *b, double *c) {
    int i;
    double sum_1, sum_x, sum_x2, sum_x3, sum_x4, sum_y, sum_xy, sum_x2y;
    sum_1 = sum_x = sum_x2 = sum_x3 = sum_x4 = sum_y = sum_xy = sum_x2y = 0;

    // 和を計算
    for (i = 0; i < n; i++) {
        sum_1 += 1;
        sum_x += x[i];
        sum_x2 += pow(x[i], 2);
        sum_x3 += pow(x[i], 3);
        sum_x4 += pow(x[i], 4);
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2y += pow(x[i], 2) * y[i];
    }

    // ガウスの消去法
    double X[3][4] = {
        {sum_x4, sum_x3, sum_x2, sum_x2y},
        {sum_x3, sum_x2, sum_x,  sum_xy},
        {sum_x2, sum_x,  sum_1,  sum_y}
    };

    gauss(X);

    // 結果を返却
    *a = X[0][3];
    *b = X[1][3];
    *c = X[2][3];
}

// ガウスの消去法
void gauss(double X[3][4]) {
    int i, j, k;

    // 前進消去
    for (i = 0; i < 3; i++) {
        double temp;

        // ピポット選択
        for (j = i; j < 3; j++) {
            if (X[j][i] > X[i][i]) {
                for (k = 0; k < 4; k++) {
                    temp = X[i][k];
                    X[i][k] = X[j][k];
                    X[j][k] = temp;
                }
            }
        }

        temp = X[i][i];
        for (j = 0; j < 4; j++)
            X[i][j] /= temp;

        for (j = i + 1; j < 3; j++) {
            temp = X[j][i];
            for (k = 0; k < 3 + 1; k++)
                X[j][k] -= X[i][k] * temp;
        }
    }

    // 後退代入
    for (i = 2; i >= 1; i--) {
        for (j = i; j < 3; j++) {
            X[i - 1][3] -= X[j][3] * X[i - 1][j];
            X[i - 1][j] = 0;
        }
    }
}

// 分散
double variance(double x[], int n) {
    return covariance(x, x, n);
}

// 共分散
double covariance(double x[], double y[], int n) {
    int i;
    double sum = 0;
    double ave_x = average(x, n), ave_y = average(y, n);

    for (i = 0; i < n; i++)
        sum += (x[i] - ave_x) * (y[i] - ave_y);

    return sum / n;
}

// 平均
double average(double x[], int n) {
    int i;
    double sum = 0;

    for (i = 0; i < n; i++)
        sum += x[i];

    return sum / n;
}
