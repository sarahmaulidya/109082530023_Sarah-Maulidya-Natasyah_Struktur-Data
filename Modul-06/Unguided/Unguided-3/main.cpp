#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi({"D001", "hitam", 90}));
    insertLast(L, alokasi({"D003", "putih", 70}));
    insertLast(L, alokasi({"D004", "kuning", 90}));

    infotype x;
    cout << "Masukkan Nomor Polisi yang akan dihapus   : ";
    cin >> x.nopol;

    address target = findElm(L, x);
    address P = Nil;

    if (target == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol
             << " tidak ditemukan." << endl;
        return 0;
    }

    if (target == L.First) {
        deleteFirst(L, P);
    } else if (target == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(target->prev, P);
    }

    cout << "Data dengan nomor polisi " << P->info.nopol
         << " berhasil dihapus." << endl;

    dealokasi(P);

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    return 0;
}