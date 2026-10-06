#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input angka 0-100: ";
    cin >> n;
    
    string kata[] {
        "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };

    if (n >= 0 && n <= 19) {
        cout << n << " : " << kata[n] << endl;
    } else if (n >= 20 && n <= 99) {
        int puluhan = n / 10;
        int satuan = n % 10;

        cout << n << " : " << kata[puluhan] << " puluh";

        if (satuan > 0) {
            cout << " " << kata[satuan];
        }
        cout << endl;
        
    } else if (n == 100) {
        cout << n << " : seratus" << endl;
    } else {
        cout << "Angka harus 0-100." << endl;
    }

    return 0;
}