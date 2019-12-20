#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define N 3

// 浮動小数点の誤差を考慮した等価判定
int fequal(double a, double b) {
    return fabs(a - b) <= DBL_EPSILON;
}

// 行列を表示
void dispMatrix(double A[N][N + 1]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N + 1; j++)
            printf("%3d", A[i][j]);

        printf("\n");
    }
}

int main(void) {
    int i, j, k;
    double ratio;

    double X[N][N + 1] = {
        {2, 2, 6,  24},
        {3, 5, 13, 52},
        {5, 8, 24, 93}
    };

    // 前進消去
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            ratio = X[j][i] / X[i][i];

            for (k = i; k < N + 1; k++) {
                X[j][k] -= ratio * X[i][k];
            }
        }
    }

    // 後退代入
    for (i = N - 1; i > 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            ratio = X[j][i] / X[i][i];

            for (k = N; k >= 0; k--) {
                X[j][k] -= ratio * X[i][k];
            }
        }
    }

    for (i = 0; i < N; i++) {
        X[i][N - 1] /= X[i][i];
        X[i][i] /= X[i][i];
    }

    dispMatrix(X);

    return 0;
}
