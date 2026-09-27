#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "Input angka pertama: ";
    cin >> angka1;
    cout << "Input angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan " << angka1 << " + " << angka2 << " = " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan " << angka1 << " - " << angka2 << " = " << angka1 - angka2 << endl;
    cout << "Hasil perkalian " << angka1 << " x " << angka2 << " = " << angka1 * angka2 << endl;
   
    if (angka2 != 0) {
        cout << "Hasil pembagian " << angka1 << " / " << angka2 << " = " << angka1 / angka2 << endl;
    } else {
        cout << "Angka kedua tidak boleh 0.";
    }   
    
    return 0;
}