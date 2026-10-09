#include <iostream>
#include "array.h"
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {11, 22, 33},
        {44, 55, 66},
        {77, 88, 99}
    };

    int x = 20;
    int y = 30;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar: " << endl;
    tampilArray(A);

    cout << "\nArray B sebelum ditukar: " << endl;
    tampilArray(B);

    tukarArray(A, B, 0, 0, 1, 1);

    cout << "Array A setelah ditukar: " << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar: " << endl;
    tampilArray(B);

    cout << "\nSebelum pointer ditukar: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah pointer ditukar: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}