#include <iostream> 
#include <random>
#include "LinearSolve.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    float mas[] = { 1,2,4,2 };
    float mas2[] = { 1,1 };

    Matrix M(mas, 2, 2);
    Vector V(mas2,2);
    
    show(V);
    cout << endl;
    
    V = M * V;

    cout <<"Len: " << V.GetLenght() << endl;

    show(V);
}