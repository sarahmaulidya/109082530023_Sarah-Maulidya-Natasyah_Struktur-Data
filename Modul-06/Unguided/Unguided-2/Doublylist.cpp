#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil; 
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil; 
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) { 
        delete P; 
        P = Nil; 
    }
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << '\n';
        cout << "warna     : " << P->info.warna << '\n';
        cout << "tahun     : " << P->info.thnBuat << '\n';
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (P == Nil) {
        return;
    }
    P->next = Nil;
    P->prev = L.Last;
    if (L.Last != Nil) {
        L.Last->next = P;
    } else {
        L.First = P;
    }
    L.Last = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}