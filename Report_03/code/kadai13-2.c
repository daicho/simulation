#include <stdio.h>
#include <math.h>

#define N 7

void quadratic(double[N], double[N], double *, double *, double *);
void gauss(double[3][4]);

int main(void) {
    double a, b, c;
    double x[N] = {0.0,   0.1,   0.2,   0.3,   0.4,   0.5,   0.6};
    double y[N] = {0.000, 0.034, 0.138, 0.282, 0.479, 0.724, 1.120};

    quadratic(x, y, &a, &b, &c);
    printf("y = %.8f x^2 + %.8f x + %.8f\n", a, b, c);

    return 0;
}

// 二次方程式による最小二乗法
void quadratic(double x[N], double y[N], double *a, double *b, double *c) {
    int i;
    double sum_1, sum_x, sum_x2, sum_x3, sum_x4, sum_y, sum_xy, sum_x2y;
    sum_1 = sum_x = sum_x2 = sum_x3 = sum_x4 = sum_y = sum_xy = sum_x2y = 0;

    // 和を計算
    for (i = 0; i < N; i++) {
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
