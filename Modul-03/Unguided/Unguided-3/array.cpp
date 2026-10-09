#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3],
                int barisA, int kolomA,
                int barisB, int kolomB) {
        int temp;
        
        temp = A[barisA][kolomA];
        A[barisA][kolomA] = B[barisB][kolomB];
        B[barisB][kolomB] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}