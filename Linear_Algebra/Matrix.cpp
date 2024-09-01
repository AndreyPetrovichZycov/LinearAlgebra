#include "Matrix.h"

void del(float** a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

Matrix::Matrix() {
    mat = 0;
    n = 0, m = 0;
}


Matrix::Matrix(int n, int m) {
    this->m = m;
    this->n = n;
    this->mat = new float* [n];
    for (int i = 0; i < n; i++) {
        this->mat[i] = new float[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            this->mat[i][j] = 0;
        }
    }
}

Matrix::Matrix(float** a, int n, int m) {
    mat = new float* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new float[m];
        for (int j = 0; j < m; j++) {
            this->mat[i][j] = a[i][j];
        }
    }
    this->n = n;
    this->m = m;
}

Matrix::Matrix(float* a, int n, int m) {
    mat = new float* [n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        mat[i] = new float[m];
        for (int j = 0; j < m; j++) {
            this->mat[i][j] = a[k];
            k++;
        }
    }

    this->n = n;
    this->m = m;
}

Matrix::Matrix(const Matrix& matr) {
    this->n = matr.n;
    this->m = matr.m;
    this->mat = new float* [n];
    for (int i = 0; i < n; i++) {
        this->mat[i] = new float[m];
    }
    for (int i = 0; i < matr.n; i++) {
        for (int j = 0; j < matr.m; j++) {
            this->mat[i][j] = matr.mat[i][j];
        }
    }
}

void Matrix::transpose() {
    int rows = this->n, cols = this->m;
    Matrix tmp(this->mat, rows, cols); //сохраняем копию обьекта 
    del(mat, n);
    this->mat = new float* [cols];
    for (int i = 0; i < cols; i++) {
        mat[i] = new float[rows];
        for (int j = 0; j < rows; j++) {
            this->mat[i][j] = tmp.mat[j][i];
        }
    }
    this->n = cols;
    this->m = rows;
}


void Matrix::operator=(const Matrix& other) {
    if (this->n == other.n && this->m == other.m) {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                this->mat[i][j] = other.mat[i][j];
            }
        }
    }
    else {
        std::cout << "size are not the same" << std::endl;
    }
}


Matrix&  Matrix::operator()(int i, int j, float a) {
    this->mat[i][j] = a;
    return (*this);
}


Matrix Matrix::operator+(const Matrix& other) {
    int rows = this->n, cols = this->m;
    if (this->n == other.n && this->m == other.m) {
        Matrix tmp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                tmp.mat[i][j] = other.mat[i][j] + this->mat[i][j];
            }
        }
        return tmp;
    }
    else {
        std::cout << "size are not the same!" << std::endl;
        return *this;
    }
}


Matrix Matrix::operator*(const Matrix& other) {
    if (this->n == other.m && this->m == other.n) {
        Matrix tmp(std::min(n, m), std::min(n, m));
        float s = 0;
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < other.m; j++) {
                s = 0;
                for (int k = 0; k < std::max(n, m); k++) {
                    s += this->mat[i][k] * other.mat[k][j];
                }
                tmp.mat[i][j] = s;
            }
        }
        return tmp;
    }
    else {
        std::cout << "size are not the same" << std::endl;
        return *this;
    }

}

Matrix Matrix::operator*(float scalar) {
    Matrix tmp(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp.mat[i][j] = mat[i][j] * scalar;
        }
    }
    return tmp;
}


float** Matrix::GetMatrix() {
    return mat;
}



Matrix::~Matrix() {
    del(mat, this->n);
    //cout<<"matrix was deleted" << endl;
}

int Matrix::getRowSize() {
    return n;
}

int Matrix::getColumSize() {
    return m;
}

void show(Matrix& a) {

    for (int i = 0; i < a.getRowSize(); i++) {
        for (int j = 0; j < a.getColumSize(); j++) {
            std::cout << a.GetMatrix()[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


