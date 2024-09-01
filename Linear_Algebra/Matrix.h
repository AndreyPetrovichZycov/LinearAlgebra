#pragma once
#include <iostream>
#include <math.h>
#include "Vector.h"

void del(float** a, int n);

class Matrix
{
    int n = 0, m = 0; //n - row size, m - col size
    float** mat = nullptr;
    friend void del(float** a, int n);
    friend class Vector;
    friend float det(Matrix A);

public:
    Matrix();

    Matrix(int n, int m);

    Matrix(float** a, int n, int m);

    Matrix(float* a, int n, int m);

    Matrix(const Matrix& matr);

    void operator=(const Matrix& other);

    Matrix& operator()(int i, int j, float a);

    Matrix operator+(const Matrix& other);

    Matrix operator*(const Matrix& other);

    Matrix operator*(float scalar);

    void transpose();

    int getRowSize();

    int getColumSize();

    float** GetMatrix();

    ~Matrix();
};


float det(Matrix A);

void show(Matrix& a);
