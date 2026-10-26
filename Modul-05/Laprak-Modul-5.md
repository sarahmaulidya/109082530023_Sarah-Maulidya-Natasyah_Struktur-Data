# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) </h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A. Singly Linked List <br/>
Linked list adalah struktur data yang berisi kumpulan elemen (node) yang saling terhubung satu sama lain [2]. Linked list dapat dibuat dengan pointer, sehingga jumlah elemennya dapat bertambah atau berkurang secara dinamis [2]. Singly linked list adalah linked list yang setiap node-nya hanya memiliki satu pointer ke node berikutnya [2], sehingga penelusurannya hanya dapat dilakukan dari depan ke belakang. Setiap node mempunyai dua bagian, yaitu ```info``` untuk menyimpan data dan ```next``` untuk menunjuk node berikutnya [1][2]. Node pertama ditunjuk oleh ```first``` (pada beberapa sumber disebut ```head```) [1][2], sedangkan node terakhir mempunyai nilai ```next = Nil``` [1][2]. Jika nilai ```first = Nil```, berarti list tersebut kosong [1].

### B. Deklarasi Struktur Data <br/>
Deklarasi struktur data pada singly linked list ditulis pada file header (```.h```) [1]. Contohnya:
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
```infotype``` adalah tipe data yang disimpan dengan tipe integer, ```address``` adalah pointer ke elemen, dan ```list``` digunakan untuk menyimpan nilai ```first``` sebagai penunjuk elemen pertama. Untuk mengakses isi node melalui pointer, digunakan tanda panah, contohnya ```P->info``` dan ```P->next``` [1].

### C. Searching <br/>
Searching adalah operasi untuk mencari node tertentu di dalam list [1]. Caranya adalah dengan mengunjungi node satu per satu dari awal, lalu berhenti jika node yang dicari sudah ditemukan atau list sudah habis [1]. Operasi ini penting karena dapat membantu operasi lainnya seperti insert after, delete after, dan update [1].

Pada searching terdapat beberapa fungsi, salah satunya adalah ```findElm```, yang digunakan untuk mencari elemen dengan ```info = X``` [1]. Jika nilainya ditemukan, fungsi akan mengembalikan address elemen tersebut, dan jika tidak ditemukan, fungsi akan mengembalikan nilai ```Nil``` [1]. Selain itu, terdapat fungsi ```fFindElm``` yang digunakan untuk memeriksa apakah alamat P ada di dalam list (menghasilkan nilai ```true``` atau ```false```) dan fungsi ```findBefore``` yang digunakan untuk mencari elemen sebelum P [1].
```C++
address findElm(list L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

### D. Operasi Dasar pada List <br/>
#### 1. createList, Alokasi, dan Dealokasi <br/>
Operasi ```createList``` digunakan untuk membuat list kosong dengan mengisi nilai ```first``` dengan ```Nil``` [1]. Operasi ```alokasi``` digunakan untuk memesan memori untuk node baru, sedangkan operasi ```dealokasi``` digunakan untuk mengembalikan memori node yang sudah tidak dipakai ke sistem [1].
#### 2. Insert <br/>
```Insert``` adalah operasi yang digunakan untuk menambah node ke dalam list [1]. ```Insert``` dibagi menjadi tiga jenis, yaitu insert first yang menambah node di awal list, insert after yang menambah node setelah node tertentu, dan insert last yang menambah node di akhir list [1]. Pada insert first, node baru ditempatkan di awal list [1]. Caranya, node baru disambungkan ke node pertama, lalu ```first``` dipindahkan ke node baru tersebut. Contohnya sebagai berikut:
```C++
void insertFirst(list &L, address P) {
    P->next = L.first;
    L.first = P;
}
```
#### 3. Delete <br/>
Delete adalah operasi yang digunakan untuk menghapus node dari list [1]. Terdapat beberapa jenis delete, yaitu delete first untuk menghapus node pertama, delete last untuk menghapus node terakhir, dan delete after untuk menghapus node setelah node tertentu [1]. Alamat node yang dilepas disimpan pada ```P```, lalu node tersebut dapat didealokasikan [1].
#### 4. printInfo dan nbList <br/>
```printInfo``` digunakan untuk menampilkan semua info di dalam list dengan menelusuri node dari ```first``` sampai nilai ```Nil```, sedangkan ```nbList``` digunakan untuk mengembalikan jumlah elemen pada list [1]. Contohnya sebagai berikut:
```C++
void printInfo(list L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```
Cara menelusuri node satu per satu ini sama dengan yang digunakan pada operasi searching.

### E. ADT Singly Linked List <br/>
Semua operasi di atas termasuk primitif yang menjadi bagian dari Abstract Data Type (ADT) singly linked list [1]. ADT ini disimpan dalam dua file, yaitu file header (```.h```) yang berisi deklarasi tipe data dan prototipe fungsi/prosedur, serta file (```.cpp```) yang berisi implementasinya [1]. Agar dapat digunakan, file ```.h``` di-include pada program utama (```main.cpp```).

## Guided
### a. File listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
### b. File listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
### c. File main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
### Penjelasan
#### a. File listBuah.h
File ```listBuah.h``` adalah file header yang berisi deklarasi struktur data dan daftar fungsi yang digunakan. Struct ```buah``` digunakan untuk menyimpan nama, jumlah, dan harga buah, sedangkan struct ```node``` berisi ```isidata``` untuk menyimpan data buah dan ```next``` untuk menunjuk ke node berikutnya. Struct ```linkedlist``` berisi ```first``` yaitu alamat node pertama, dan list dianggap kosong jika ```first``` bernilai ```Nil```. Di bagian bawah terdapat prototype operasi dasar, update, dan searching.
#### b. File listBuah.cpp
File ```listBuah.cpp``` berisi implementasi dari semua fungsi yang dideklarasikan di ```listBuah.h```. Operasi dasarnya meliputi membuat list kosong, mengalokasi dan mendealokasi node, serta menampilkan list dan menghitung jumlah node. Operasi insert dan delete dapat dilakukan di awal, di akhir, atau setelah node tertentu. Operasi update mengganti data node pertama, terakhir, atau setelah node tertentu melalui input, sedangkan operasi searching mencari node berdasarkan nama, alamat, atau rentang harga. Seluruh operasi tersebut menelusuri list dari ```first``` sampai ```Nil```.

#### c. File main.cpp
File ```main.cpp``` adalah program utama untuk mencoba semua operasi pada list buah. Pertama dibuat lima node buah yang disisipkan sehingga urutannya menjadi Jeruk, Pir, Semangka, Apel, Durian. Setelah itu beberapa node diupdate, lalu dilakukan pencarian berdasarkan data, alamat, dan rentang harga. Kemudian node pertama, terakhir, dan node setelah Pir dihapus, dan terakhir seluruh list dihapus sehingga jumlah node menjadi 0.

## Unguided 

### 2. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:
```C++
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address)
```
Kemudian buat implementasi ADT Singly Linked list pada file "Singlylist.cpp".
Adapun isi data
![Gambar 5-1 Ilustrasi elemen](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-05/Gambar_5-1.png?raw=true)

Cobalah hasil implementasi ADT pada file “main.cpp”
```C++
int main()
{
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

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L)
    return 0;
}
```
Contoh output:
```9 12 8 0 2```

#### a. File Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

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
#### b. File Singlylist.cpp
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
#### c. File main.cpp
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
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-05/Screenshot_Output/Output-Unguided-2.png?raw=true)

### Penjelasan
#### a. File Singlylist.h
File ```Singlylist.h``` adalah file header yang berisi deklarasi struktur data dan daftar fungsi yang digunakan. ```Nil``` didefinisikan sebagai ```NULL``` untuk menandai pointer yang kosong, dan ```#ifndef``` digunakan agar file ini tidak di-include berulang kali. Node dibuat melalui struct ```ElmList``` yang berisi ```info``` untuk menyimpan data dan ```next``` untuk menunjuk ke node berikutnya, sedangkan struct ```List``` berisi ```first``` yaitu alamat node paling depan. Di bagian bawah terdapat prototype ```createList```, ```alokasi```, ```dealokasi```, ```printInfo```, dan ```insertFirst```.

#### b. File Singlylist.cpp
File ```Singlylist.cpp``` berisi isi dari semua fungsi yang sudah dideklarasikan di ```Singlylist.h```. ```createList``` digunakan untuk membuat list kosong dengan mengisi ```first``` dengan ```Nil```. ```alokasi``` digunakan untuk membuat node baru dengan ```new``` lalu mengembalikan alamatnya, sedangkan ```dealokasi``` digunakan untuk menghapus node dengan ```delete```. ```printInfo``` menampilkan isi list dari ```first``` sampai ```Nil```, dan ```insertFirst``` memasukkan node baru di depan list, yaitu dengan mengarahkan ```next``` node baru ke ```first``` lalu memindahkan ```first``` ke node baru tersebut.

#### c. File main.cpp
File ```main.cpp``` adalah program utama untuk mencoba ADT yang sudah dibuat. Pertama dibuat list ```L``` lalu dikosongkan dengan ```createList```. Setelah itu lima node dibuat dengan ```alokasi``` yang berisi 2, 0, 8, 12, dan 9, dan setiap node langsung dimasukkan ke depan list dengan ```insertFirst```. Karena selalu dimasukkan di depan, urutan list menjadi terbalik, yaitu 9, 12, 8, 0, 2, lalu isinya ditampilkan dengan ```printInfo```.

### 3. Carilah elemen dengan info 8 dengan membuat fungsi baru.
```fungsi findElm( L : List, x : infotype ) : address```

Contoh output:
```8 ditemukan dalam list```
#### a. File Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

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
address findElm(List L, infotype x);

#endif
```
#### b. File Singlylist.cpp
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

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
#### c. File main.cpp
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

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-05/Screenshot_Output/Output-Unguided-3.png?raw=true)

### Penjelasan
#### a. File Singlylist.h
File ```Singlylist.h``` adalah file header yang berisi deklarasi struktur data dan daftar fungsi yang digunakan. ```Nil``` didefinisikan sebagai ```NULL``` untuk menandai pointer yang kosong, dan ```#ifndef``` digunakan agar file ini tidak di-include berulang kali. Node dibuat melalui struct ```ElmList``` yang berisi ```info``` untuk menyimpan data dan ```next``` untuk menunjuk ke node berikutnya, sedangkan struct ```List``` berisi ```first``` yaitu alamat node paling depan. Di bagian bawah terdapat prototype ```createList```, ```alokasi```, ```dealokasi```, ```printInfo```, ```insertFirst```, dan fungsi baru ```findElm``` untuk mencari node.

#### b. File Singlylist.cpp
File ```Singlylist.cpp``` berisi isi dari semua fungsi yang sudah dideklarasikan di ```Singlylist.h```. ```createList``` digunakan untuk membuat list kosong dengan mengisi ```first``` dengan ```Nil```. ```alokasi``` digunakan untuk membuat node baru dengan ```new``` lalu mengembalikan alamatnya, sedangkan ```dealokasi``` digunakan untuk menghapus node dengan ```delete```. ```printInfo``` menampilkan isi list dari ```first``` sampai ```Nil```, dan ```insertFirst``` memasukkan node baru di depan list. ```findElm``` digunakan untuk mencari node yang ```info```-nya sama dengan ```x```, lalu mengembalikan alamat node tersebut jika ditemukan atau ```Nil``` jika tidak ditemukan.

#### c. File main.cpp
File ```main.cpp``` adalah program utama untuk mencoba ADT yang sudah dibuat. Pertama dibuat list ```L``` lalu dikosongkan dengan ```createList```. Setelah itu lima node dibuat dengan ```alokasi``` yang berisi 2, 0, 8, 12, dan 9, dan setiap node langsung dimasukkan ke depan list dengan ```insertFirst```, sehingga urutan list menjadi 9, 12, 8, 0, 2. Kemudian ```findElm``` digunakan untuk mencari node yang berisi 8 dan hasilnya disimpan di ```hasil```. Jika ```hasil``` bukan ```Nil``` maka muncul tulisan "8 ditemukan dalam list", dan jika ```Nil``` maka muncul "8 tidak ditemukan dalam list". Karena angka 8 ada di dalam list, outputnya adalah "8 ditemukan dalam list".

### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).
Contoh output:
```Total info dari kelima elemen adalah 31```
#### a. File Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

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
int totalInfo(List L);

#endif
```
#### b. File Singlylist.cpp
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

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```
#### c. File main.cpp
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

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```
### Output Unguided  4:

##### Output 1
![Screenshot Output Unguided 4](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-05/Screenshot_Output/Output-Unguided-4.png?raw=true)

### Penjelasan
#### a. File Singlylist.h
File ```Singlylist.h``` adalah file header yang berisi deklarasi struktur data dan daftar fungsi yang digunakan. ```Nil``` didefinisikan sebagai ```NULL``` untuk menandai pointer yang kosong, dan ```#ifndef``` digunakan agar file ini tidak di-include berulang kali. Node dibuat melalui struct ```ElmList``` yang berisi ```info``` untuk menyimpan data dan ```next``` untuk menunjuk ke node berikutnya, sedangkan struct ```List``` berisi ```first``` yaitu alamat node paling depan. Di bagian bawah terdapat prototype ```createList```, ```alokasi```, ```dealokasi```, ```printInfo```, ```insertFirst```, dan fungsi baru ```totalInfo``` untuk menghitung jumlah semua info.

#### b. File Singlylist.cpp
File ```Singlylist.cpp``` berisi isi dari semua fungsi yang sudah dideklarasikan di ```Singlylist.h```. ```createList``` digunakan untuk membuat list kosong dengan mengisi ```first``` dengan ```Nil```. ```alokasi``` digunakan untuk membuat node baru dengan ```new``` lalu mengembalikan alamatnya, sedangkan ```dealokasi``` digunakan untuk menghapus node dengan ```delete```. ```printInfo``` menampilkan isi list dari ```first``` sampai ```Nil```, dan ```insertFirst``` memasukkan node baru di depan list. ```totalInfo``` digunakan untuk menjumlahkan semua ```info``` di dalam list, yaitu dengan mengisi variabel ```total``` dengan 0 terlebih dahulu, lalu menelusuri list sambil menambahkan ```info``` setiap node ke ```total```, kemudian hasilnya dikembalikan.

#### c. File main.cpp
File ```main.cpp``` adalah program utama untuk mencoba ADT yang sudah dibuat. Pertama dibuat list ```L``` lalu dikosongkan dengan ```createList```. Setelah itu lima node dibuat dengan ```alokasi``` yang berisi 2, 0, 8, 12, dan 9, dan setiap node langsung dimasukkan ke depan list dengan ```insertFirst```, sehingga urutan list menjadi 9, 12, 8, 0, 2. Kemudian ```totalInfo``` dipanggil untuk menjumlahkan semua info, yaitu 9 + 12 + 8 + 0 + 2 = 31, dan hasilnya ditampilkan dengan tulisan "Total info dari kelima elemen adalah 31".

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa singly linked list adalah struktur data yang terdiri dari node-node yang saling terhubung melalui pointer, dan setiap node hanya memiliki satu pointer ke node berikutnya. Karena menggunakan alokasi memori dinamis, jumlah node dapat bertambah atau berkurang sesuai kebutuhan. Operasi dasarnya, yaitu insert, delete, update, dan searching, dilakukan dengan mengatur pointer ```next``` dan menelusuri list dari ```first``` sampai ```Nil```. Seluruh operasi tersebut dapat disusun sebagai ADT, dengan deklarasi pada file ```.h``` dan implementasi pada file ```.cpp```.

## Referensi
[1] Informatics Lab, Fakultas Informatika, Telkom University. (t.t.). Modul 5: Singly Linked List (Bagian Kedua). Telkom University.
[2] A. F. Akbar, "Memahami Konsep dan Jenis-Jenis Linked List dalam Struktur Data," D4 Manajemen Informatika, Universitas Negeri Surabaya, 3 September 2024. [Online]. Tersedia: https://terapan-ti.vokasi.unesa.ac.id/post/memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data