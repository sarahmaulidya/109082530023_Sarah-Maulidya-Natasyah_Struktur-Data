#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

void cetak(int a, int b, int c) {
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "-- Call by Pointer --" << endl;
    cout << "Sebelum : ";
    cetak(a, b, c);
    tukarPointer(&a, &b, &c);
    cout << "Sesudah : ";
    cetak(a, b, c);

    a = 10; b = 20; c = 30;

    cout << "\n-- Call by Reference --" << endl;
    cout << "Sebelum : ";
    cetak(a, b, c);
    tukarReference(a, b, c);
    cout << "Sesudah : ";
    cetak(a, b, c);

    return 0;
}