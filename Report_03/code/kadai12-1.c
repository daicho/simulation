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
            if (j != N)
                printf("%6.2f ", A[i][j]);
            else
                printf("| %6.2f\n", A[i][j]);
    }
}

int main(void) {
    int i, j, k;
    double ratio;

    double X[N][N + 1] = {
        {-2, 2, 0,  0},
        {3, -3, 1, 1},
    	{2, 1, 6, 9}
    };

    dispMatrix(X);
    printf("\n");

	// 前進代入
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

    dispMatrix(X);
    printf("\n");

	// 後退代入
    for (i = N - 1;i >= 1;i--) {
        for (j = i; j < N; j++) {
            X[i - 1][N] -= X[j][N] * X[i - 1][j];
            X[i - 1][j] = 0;
        }
    }

    dispMatrix(X);

    return 0;
}
