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
        cout << "Nomor Polisi   : " << P->info.nopol << endl;
        cout << "Warna          : " << P->info.warna << endl;
        cout << "Tahun          : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}


void insertLast(List &L, address P) {
    if (P == Nil) return;

    P->prev = L.Last;
    P->next = Nil;

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

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;

    L.First = P->next;

    if (L.First != Nil) {
        L.First->prev = Nil;
    } else {
        L.Last = Nil;
    }

    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;

    L.Last = P->prev;

    if (L.Last != Nil) {
        L.Last->next = Nil;
    } else {
        L.First = Nil;
    }

    P->prev = Nil;
}

void deleteAfter(address Prec, address &P) {
    P = Nil;
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != Nil) {
        P->next->prev = Prec;
    }

    P->prev = Nil;
    P->next = Nil;
}