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
#### 2. Node terakhir menunjukkan ke NULL, kecuali pada list sirkular [1].
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
Proses membuat list baru dengan mengisi nilai awal ```first``` dengan ```NULL```, sehingga list kosong [1].
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
Insert last adalah menyisipkan elemen di akhir list dengan cara mencari elemen terakhir (Q), lalu menghubungkan ```Q -> next = P``` [1].
##### c. Insert After
Insert after adalah menyisipkan elemen setelah node tertentu (Q) dengan cara ```P -> next = Q -> next;``` lalu ````Q -> next = P;```.
#### 6. View
Operasi ini menampilkan isi node dengan cara menelususri list dari elemen pertama, mengunjungi setiap node, lalu menampilkan data yang tersimpan sampai bertemu nilai ```NULL```. Pada ADT, fungsi ini biasanya diberi nama ```printInfo()```.
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
Delete last adalah menghapus elemen terakhir [1]. Langkahnya diambil dari elemen terakhir (P), mencari elemen sebelumnya (Q), lalu set ```Q -> next = NULL```.
##### c. Delete After
Delete after adalah menghapus node setelah node tertentu (P) [1]. Langkahnya ```Q = P -> next```, lalu ```P -> next = Q -> next;``` dan ```Q -> next = NULL;```.
Setelah dilepaas dari list, elemen akakn dikembalikan atau didealokasi dengan ```dealokasi(P)```. Selain itu, ada fungsi ```delAll(L)``` untuk membebeaskan seluruh memori elemen sehingga list menjadi kosong [1]. 
####  8. Update
Update adalah operasi untuk mengubah data ynag ada di dalam list [1]. Prosesnya biasanya diawali dengan mencari node yang datanya akan diubah, kemudian isi node tersebut diganti dengan data yang baru [1].

### E. Primitif pada ADT Linked List
Semua operasi dasar yang sudah dijelaskan diatas adalah operasi primitif [1]. Primitif-primitif tersebut merupakan bagian dari ADT (Abstract Data Type) list yang disimpan dalam dua file, yaitu:
#### 1. File ```.h``` berisi protoripe fungsi/prosedur dan tipe data yang dipakai [1].
#### 2. File ```.cpp``` berisi implementasi dari fungsi/prosedur tersebut [1].
Agar primitif dapat diiakses, harus diimport ```#include``` terhadap file ```.h```-nya pada program utama (```main.cpp```) [1].

## Guided
### 1. 
```C++
kode
```
penjelasan
### 2. 
```C++
kode
```
penjelasan
### 3. 
```C++
kode
```
penjelasan 
### 4. 
```C++
kode
```
penjelasan
### 5. 
```C++
kode
```
penjelasan
### 6. 
```C++
kode
```
penjelasan
### 7. 
```C++
kode
```
penjelasan
### 8. 
```C++
kode
```
penjelasan
### 9. 
```C++
kode
```
penjelasan
### 10.
```C++
kode
```
penjelasan
### 11. 
```C++
kode
```
penjelasan


## Unguided 

### 1. soal

```C++
kode
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1]()

##### Output 2
![Screenshot Output Unguided 1.2]()

penjelasan

### 2. soal

```C++
kode
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2.1]()

penjelasan

### 3. soal
```C++
kode
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3.1]()
![Screenshot Output Unguided 3.1]()

penjelasan

## Kesimpulan
kesimpulan

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 2: Pengenalan Bahasa C++ (Bagian Kedua). Telkom University. 
<br>[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.