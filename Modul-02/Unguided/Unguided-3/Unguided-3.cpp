#include <iostream>
using namespace std;

int cariMinimum(int *pa, int n);
int cariMaksimum(int *pa, int n);
void hitungRataRata(int *pa, int n);
void tampilkanArray(int *pa, int n);

void tampilkanArray(int *pa, int n) {
    cout << "Isi array : ";
    for (int i = 0; i < n; i++)
        cout << *(pa + i) << " ";
    cout << endl;
}

int cariMinimum(int *pa, int n) {
    int min = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) < min)
            min = *(pa + i);
    }
    return min;
}

int cariMaksimum(int *pa, int n) {
    int maks = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) > maks)
            maks = *(pa + i);
    }
    return maks;
}

void hitungRataRata(int *pa, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + *(pa + i);
    float rata_rata = (float) total / n;
    cout << "Nilai rata-rata = " << rata_rata << endl;
}

int main() {
    int pilihan;
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray(&arrA[0], ukuran);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(&arrA[0], ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(&arrA[0], ukuran) << endl;
                break;
            case 4:
                hitungRataRata(&arrA[0], ukuran);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}