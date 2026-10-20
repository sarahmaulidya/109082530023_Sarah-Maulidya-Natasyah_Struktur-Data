# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A. Linked List dengan Pointer <br/>
LInked list atau biasa disebut list adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berhubungan [1]. Struktur ini bersifat fleksibel karena dapat bertambah dan berkurang sesuai kebutuhan [1]. Data yang disimpan dalam linked list bisa berupa data tunggal, misalnya nama bertipe string, atau data majemuk (record), seperti pada data mahasiswa  yang terdiri dari nama, NIM, dan alamat [1]. Linked list dapat dibuat dengan array maupun pointer [1]. Pada praktikum ini linked list yang digunakan adalah pointer karena beberapa alasan, yaitu: 
#### 1. Array bersifat statis, sedangkan pointer bersifat dinamis [1].
#### 2. Elemen pada linked list saling berhubungan, sehingga lebih mudah dihubungkan dengan pointer [1].
#### 3. Sifat linked list yang fleksibel lebih cocok dengan pointer yang bisa diatur sesuai dengan kebutuhan [1].
#### 4. Array lebih cocok untuk data yang jumlah maksimumnya sudah diketahui dari awal [1].
Elemen linked list yang diakses dengan pointer dapat menggunakan tanda panah (->) atau tanda titik (.) [1].

### B. Singly Linked List <br/>
Singly linked list adalah model linked list yang hanya memiliki satu arah pointer [1]. Setiap elemen terdiri dari dua bagian, yaitu data (informasi utama yang disimpan) dan successor (bagian yang menghubungkan ke elemen berikutnya) [1].
Sifat-sifat linked list:
#### 1. Hanya membutuhkan satu pointer [1].
#### 2. Node terakhir menunjukkan ke ```Nil```, kecuali pada list sirkular [1].
#### 3. Hanya bisa dibaca ke arah depan (maju) [1]. 
#### 4. Pencarian dilakukan secara sekuensial jika data tidak terurut [1].
#### 5. Penyisipan dan penghapusan di tengah list lebih mudah [1].

### C. Deklarasi Struktur Data
Deklarasi singly linked list ditulis pada file ```.h``` (header), contohnya sebagai berikut:
```C++
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};
```
```infotype``` adalah type data yang disimpan, ```address``` adalah pointer ke elemen, ```elmlist``` adalah elemen yang berisi ```info``` dan ```next```, dan ```list``` menyimpan ```first``` sebagai penunjuk elemen pertama. Jika datanya majemuk, misalnya mahasiswa, maka dibuat ```struct mahasiswa``` yang berisi nama dan NIM, lalu ```infotype``` didefinisikan sebagai ```mahasiswa```. 

### D. Operasi pada Singly Linked List
Operasi dasar pada linked list meliputi penciptaan (create), penyisipan (insert), penghapusan (delete), penelusuran dan penampilan (view), pencarian (searching), dan pengubahan (update) [1].
#### 1. Pembentukan List (CreateList)
Proses membuat list baru dengan mengisi nilai awal ```first``` dengan ```Nil```, sehingga list kosong [1].
#### 2. Alokasi Memori
Proses memesan memori untuk setiap elemen baru [1]. Pada C digunakan ```malloc```, sedangkan pada C++ digunakan ```new``` [1].
```C++
address alokasi(mahasiswa M){
    address P = new elmlist;
    P->info = M;
    return P;
}
```
#### 3. Dealokasi
Proses mengembalikan memori yang sudah tidak dipakai ke sistem [1]. Pada C digunakan ```free(p)```, sedangkan pada C++ digunakan ```delete.p``` [1].
#### 4. Pengecekan List (isEmpty)
Fungsi untuk mengecek apakah list kosong atau tidak [1]. Fungsi ini membalikkan nilai ```true``` jika list kososng dan ```false``` jika tidak.
#### 5. Insert
Insert adalah operasi menambah elemen baru ke dalam list [1]. Ada tiga jenis, diantaranya:
##### a. Insert First
Insert first adalah menyisipkan elemen di awal list dengan cara mengalokasikan elemen baru, menghubungkan ```next``` elemen baru ke elemen pertama, lalu jadikan elemen baru sebagai ```first```[1].
```C++
void insertFirst(List &L, address &P){
    P->next = L.first;
    L.first = P;
}
```
##### b. Insert Last
Insert last adalah menyisipkan elemen di akhir list dengan cara mencari elemen terakhir (Q), lalu menghubungkan ```Q->next = P``` [1].
##### c. Insert After
Insert after adalah menyisipkan elemen setelah node tertentu (Q) dengan cara ```P->next = Q->next;``` lalu ````Q->next = P;```.
#### 6. View
Operasi ini menampilkan isi node dengan cara menelususri list dari elemen pertama, mengunjungi setiap node, lalu menampilkan data yang tersimpan sampai bertemu nilai ```Nil```. Pada ADT, fungsi ini biasanya diberi nama ```printInfo()```.
#### 7. Delete
Delete adalah operasi mengambil atau menghapus elemen dari list [1]. Delete terbagi menjadi tiga jenis, yaitu:
##### a. Delete First
Delete first yaitu menghapus elemen pertama [1].
```C++
void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = (L.first)->next;
    P->next = Nil;
}
```
##### b. Delete Last
Delete last adalah menghapus elemen terakhir [1]. Langkahnya diambil dari elemen terakhir (P), mencari elemen sebelumnya (Q), lalu set ```Q->next = Nil```.
##### c. Delete After
Delete after adalah menghapus node setelah node tertentu (P) [1]. Langkahnya ```Q = P->next```, lalu ```P->next = Q->next;``` dan ```Q->next = Nil;```.
Setelah dilepaas dari list, elemen akakn dikembalikan atau didealokasi dengan ```dealokasi(P)```. Selain itu, ada fungsi ```delAll(L)``` untuk membebeaskan seluruh memori elemen sehingga list menjadi kosong [1]. 
####  8. Update
Update adalah operasi untuk mengubah data ynag ada di dalam list [1]. Prosesnya biasanya diawali dengan mencari node yang datanya akan diubah, kemudian isi node tersebut diganti dengan data yang baru [1].

### E. Primitif pada ADT Linked List
Semua operasi dasar yang sudah dijelaskan diatas adalah operasi primitif [1]. Primitif-primitif tersebut merupakan bagian dari ADT (Abstract Data Type) list yang disimpan dalam dua file, yaitu:
#### 1. File ```.h``` berisi protoripe fungsi/prosedur dan tipe data yang dipakai [1].
#### 2. File ```.cpp``` berisi implementasi dari fungsi/prosedur tersebut [1].
Agar primitif dapat diiakses, harus diimport ```#include``` terhadap file ```.h```-nya pada program utama (```main.cpp```) [1].

## Guided
### a. File list.h
```C++
//hear guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalamm satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & procedure yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi (address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
### b. File list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak 
bool isEmpty(linkedList List) {
    if(List.first == Nil) {
        return true;
    } else  {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil*/
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarangan, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesusah elemen node prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList & List, address nodeBaru) {
    /* I.S. sembarangan, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false) {
        nodeHapus = List.first;
        if(nodeHapus->next == Nil) {
            List.first->next == Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev -> next, menghapus prev -> next dari list */
    if(isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}

//function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
### c. File main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "231110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2311102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure CreateList(input/output L : List)
function alokasi (x : infotype)->address
procedure dealokasi(input/output P : address)
procedure printInfo(input L : List)
procedure insertFirst(input/output L : List, input P : address)
```
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file ```“Singlylist.cpp”```
Kemudian buat program utama didalam file ```“main.cpp”``` dengan implementasi sebagai berikut:
```C++
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P4 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L)
    return 0;
}
```
Output yang diharapkan:
```
9 12 8 0 2
```
##### a. File Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
 
#include <iostream>
using namespace std;
 
#define Nil NULL
 
typedef int infotype;
typedef struct ElmList *address;
 
struct ElmList {
    infotype info;
    address next;
};
 
struct List {
    address first;
};
 
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
 
#endif
```
##### b. File Singlylist.cpp
```C++
#include "Singlylist.h"
 
void createList(List &L) {
    L.first = Nil;
}
 
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}
 
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
 
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
```
##### c. File main.cpp
```C++
#include "Singlylist.h"
 
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);
 
    P1 = alokasi(2);
    insertFirst(L, P1);
 
    P2 = alokasi(0);
    insertFirst(L, P2);
 
    P3 = alokasi(8);
    insertFirst(L, P3);
 
    P4 = alokasi(12);
    insertFirst(L, P4);
 
    P5 = alokasi(9);
    insertFirst(L, P5);
 
    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1]()

##### Output 2
![Screenshot Output Unguided 1.2]()

penjelasan

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().
Output yang diharapkan:
```
12 0
Jumlah node : 2

- List Berhasil Terhapus -
Jumlah node : 0
```
##### a. File Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
 
#include <iostream>
using namespace std;
 
#define Nil NULL
 
typedef int infotype;
typedef struct ElmList *address;
 
struct ElmList {
    infotype info;
    address next;
};
 
struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
 
// tambahan kode soal 2
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);
 
#endif
```
##### b. File Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}
 
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}
 
void dealokasi(address &P) {
    delete P;
    P = Nil;
}
 
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
 
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
 
// tambahan kode soal 2
void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = L.first->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}
 
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first->next == Nil) {
        P = L.first;
        L.first = Nil;
    } else {
        address Q = L.first;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}
 
int nbList(List L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
##### c. File main.cpp
```C++
#include "Singlylist.h"
 
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);
 
    P1 = alokasi(2);
    insertFirst(L, P1);
 
    P2 = alokasi(0);
    insertFirst(L, P2);
 
    P3 = alokasi(8);
    insertFirst(L, P3);
 
    P4 = alokasi(12);
    insertFirst(L, P4);
 
    P5 = alokasi(9);
    insertFirst(L, P5);
 
    // tambahan kode soal no 2: penghapusan node
    address P;
 
    deleteFirst(L, P);
    dealokasi(P);
 
    deleteLast(L, P); 
    dealokasi(P);
 
    deleteAfter(L, P4, P);
    dealokasi(P);
 
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
 
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
 
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2.1]()

penjelasan


## Kesimpulan
kesimpulan

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 2: Pengenalan Bahasa C++ (Bagian Kedua). Telkom University. 