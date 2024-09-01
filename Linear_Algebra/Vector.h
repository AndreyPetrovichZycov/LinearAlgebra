#pragma once
#include <iostream>
#include "Matrix.h"

class Vector {
    int len = 0;
    float* vect = nullptr;
    friend class Matrix;
public:
    Vector();

    Vector(int n);

    Vector(const float* vect, int n);

    //конструктор копирования
    Vector(const Vector &vect);

    void operator()(int i, float val);

    void operator=(const Vector& other);

    Vector operator+(const Vector& other);

    float operator*(const Vector& vect);

    Vector& operator*(float sclr);

    float operator[](int i);

    float norma();

    int GetLenght();

    float* GetVector();

    ~Vector();
};


Vector operator*(Matrix matr, Vector vect);

void show(Vector& v);