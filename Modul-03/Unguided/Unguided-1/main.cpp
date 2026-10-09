#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;

    if (jumlah < 1 || jumlah > 10) {
        cout << "Tidak valid. Jumlah mahasiswa harus dari rentang 1-10!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMahasiswa(mhs[i]);
    }

    cout << "\n--- Data Mahasiswa ---" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        outputMahasiswa(mhs[i]);
    }
    return 0;
}