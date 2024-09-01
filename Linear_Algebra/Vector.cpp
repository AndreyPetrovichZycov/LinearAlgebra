#include "Vector.h"

Vector::Vector() {
    len = 0;
    vect = nullptr;
}

Vector::Vector(int n) {
    this->len = n;
    this->vect = new float[len];
    for (int i = 0; i < len; i++) {
        this->vect[i] = 0;
    }
}


Vector::Vector(const float* vect, int n) {
    this->len = n;
    this->vect = new float[len];
    for (int i = 0; i < n; i++) {
        this->vect[i] = vect[i];
    }
}

Vector::Vector(const Vector &vect) {
    this->len = vect.len;
    this->vect = new float[len];
    for (int i = 0; i < len; i++) {
        this->vect[i] = vect.vect[i];
    }
}

void Vector::operator()(int i, float val) {
    this->vect[i] = val;
}

void Vector::operator=(const Vector& other) {
    if (other.vect != nullptr && other.len == this->len) {
        for (int i = 0; i < other.len; i++) {
            this->vect[i] = other.vect[i];
        }
    }
    else std::cout << "size is 0 or not the same" << std::endl;
}


Vector Vector::operator+(const Vector& other) {
    if (other.vect != nullptr && this->len == other.len) {
        Vector tmp(other.len);
        for (int i = 0; i < len; i++) {
            tmp.vect[i] = this->vect[i] + other.vect[i];
        }
        return tmp;
    }
    else {
        std::cout << "error!" << std::endl;
        return *this;
    }
}

float Vector::operator*(const Vector& vect) {
    if (vect.len == this->len) {
        float s = 0;
        for (int i = 0; i < vect.len; i++) {
            s += this->vect[i] * vect.vect[i];
        }
        return s;
    }
    else return 0;

}

Vector& Vector::operator*(float sclr) {
    for (int i = 0; i < this->len; i++) {
        this->vect[i] = (this->vect[i]) * sclr;
    }
    return *this;
}

float Vector::operator[](int i) {
    return this->vect[i];
}

float Vector::norma() {
    float s = 0;
    for (int i = 0; i < this->len; i++) {
        s += (this->vect[i]) * (this->vect[i]);
    }
    return sqrt(s);
}


Vector::~Vector() {
   delete[] vect;
   //cout << "destructor" << endl;
}


int Vector::GetLenght() {
    return len;
}

float* Vector:: GetVector() {
    return vect;
}


Vector operator*(Matrix matr,Vector vect) {
    if (matr.getColumSize() == vect.GetLenght()) {
        Vector temp(matr.getRowSize());
        float s = 0;
        
        for (int i = 0; i < matr.getRowSize(); i++) {
            s = 0;
            for (int j = 0; j < matr.getColumSize(); j++) {
                s += matr.GetMatrix()[i][j] * vect.GetVector()[j];
            }
            temp.GetVector()[i] = s;
        }
        return temp;
    }
    else {
        std::cout << "size are not the same\n";
        return vect;
    }
}


void show(Vector& v) {

    for (int i = 0; i < v.GetLenght(); i++) {
        std::cout << v.GetVector()[i] << " ";
    }
    std::cout << std::endl;
}
