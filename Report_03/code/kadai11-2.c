#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define N 4

void gauss(double[N][N + 1]);
void dispMatrix(double[N][N + 1]);

int main(void) {
    double X[N][N + 1] = {
        {1, 2, 1, 5, 20.5},
        {8, 1, 3, 1, 14.5},
        {1, 7, 1, 1, 18.5},
        {1, 1, 6, 1, 9.0}
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
                printf("%6.2f ", X[i][j]);
            else
                printf("| %6.2f\n", X[i][j]);
        }
    }
}
