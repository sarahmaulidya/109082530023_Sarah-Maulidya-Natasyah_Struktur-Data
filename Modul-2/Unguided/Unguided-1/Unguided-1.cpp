#include <iostream>
using namespace std;

const int N = 3;

void inputMatriks(int m[N][N], string nama) {
    cout << "Masukkan nilai " << nama << " (input 3 angka yang dipisahkan oleh spasi)" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Baris-" << i + 1 << " : ";
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
}

void cetakMatriks(int m[N][N], string judul) {
    cout << "\n" << judul << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void tambah(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void kurang(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void kali(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    inputMatriks(A, "Matriks A");
    inputMatriks(B, "Matriks B");

    cetakMatriks(A, "Matriks A = ");
    cetakMatriks(B, "Matriks B = ");

    tambah(A, B, C);
    cetakMatriks(C, "Hasil A + B = ");

    kurang(A, B, C);
    cetakMatriks(C, "Hasil A - B = ");

    kali(A, B, C);
    cetakMatriks(C, "Hasil A x B = ");

    return 0;
}