#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define N 4

void gauss(double[N][N + 1]);
void dispMatrix(double[N][N + 1]);

int main(void) {
    double X[N][N + 1] = {
        {1.0,  0.96,   0.84,   0.64,   3.44},
        {0.96, 0.9214, 0.4406, 0.2222, 2.5442},
        {0.84, 0.4406, 1.0,    0.3444, 2.6250},
        {0.64, 0.2222, 0.3444, 1.0,    2.2066}
    };

    dispMatrix(X);
    printf("\n");

    gauss(X);
    dispMatrix(X);

    return 0;
}

// ガウスの消去法
void gauss(double X[N][N + 1]) {
    int i, j, k;

    // 前進消去
    for (i = 0; i < N; i++) {
        double temp;

        // ピポット選択
        for (j = i; j < N; j++) {
            if (X[j][i] > X[i][i]) {
                for (k = 0; k < N + 1; k++) {
                    temp = X[i][k];
                    X[i][k] = X[j][k];
                    X[j][k] = temp;
                }
            }
        }

        temp = X[i][i];
        for (j = 0; j < N + 1; j++)
            X[i][j] /= temp;

        for (j = i + 1; j < N; j++) {
            temp = X[j][i];
            for (k = 0; k < N + 1; k++)
                X[j][k] -= X[i][k] * temp;
        }
    }

    // 後退代入
    for (i = N - 1; i >= 1; i--) {
        for (j = i; j < N; j++) {
            X[i - 1][N] -= X[j][N] * X[i - 1][j];
            X[i - 1][j] = 0;
        }
    }
}

// 行列を表示
void dispMatrix(double X[N][N + 1]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N + 1; j++) {
            if (j != N)
                printf("%8.4f ", X[i][j]);
            else
                printf("| %20.16f\n", X[i][j]);
        }
    }
}
