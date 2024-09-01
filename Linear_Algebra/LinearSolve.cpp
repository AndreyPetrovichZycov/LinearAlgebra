#include "LinearSolve.h"

void Gauss(float** a, float* b, int n, int m) {
    float r;
    int i, j, k;
    for (j = 0; j < n - 1; j++) {
        for (i = j + 1; i < n; i++) {
            r = -a[i][j] / a[j][j];
            for (k = j; k < n; k++) {
                a[i][k] = a[i][k] + r * a[j][k];
            }
            b[i] = b[i] + r * b[j];
        }
    }
}



float Sum(float** a, float* x, int n, int i) {
    float S = 0;
    for (int j = i + 1; j < n; j++) {
        S = S + a[i][j] * x[j];
    }
    return S;
}



Vector Solve_Linear(Matrix A, Vector b) {
    if (A.getRowSize() == A.getColumSize() && A.getRowSize() == b.GetLenght()) {
        Vector x(b.GetLenght());
        Gauss(A.GetMatrix(), b.GetVector(), b.GetLenght(), b.GetLenght());
        for (int i = A.getColumSize() - 1; i >= 0; i--) {
            x.GetVector()[i] = (b.GetVector()[i] - Sum(A.GetMatrix(), x.GetVector(), b.GetLenght(), i)) / A.GetMatrix()[i][i];
        }
        return x;
    }
    else {
        Vector null;
        std::cout << "size are not the same" << std::endl;
        return null;
    }
}

float det(Matrix A) {
    float res = 1;
    if (A.getColumSize() == A.getRowSize()) {
        Vector b(A.n);
        Gauss(A.mat, b.GetVector(), A.n, A.m);
        for (int i = 0; i < A.n; i++) {
            res = res * A.mat[i][i];
        }
        return res;
    }
    else {
        std::cout << "matrix is not square!" << std::endl;
        return -11111111;
    }
}