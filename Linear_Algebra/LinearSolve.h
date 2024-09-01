#pragma once
#include "Matrix.h"
#include "Vector.h"


void Gauss(float** a, float* b, int n, int m);

float Sum(float** a, float* x, int n, int i);

Vector Solve_Linear(Matrix A, Vector b);

float det(Matrix A);