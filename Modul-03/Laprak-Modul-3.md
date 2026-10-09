# <h1 align="center">Laporan Praktikum Modul 3 - Abstrack Data Type (ADT) </h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A. Abstrack Data Type (ADT)<br/>
ADT adalah sebuah TYPE yang punya sekumpulan PRIMITIF (operasi dasar) untuk TYPE itu [1]. Pada ADT yang lengkap, terdapat definisi invarian dari TYPE dan aksioma yang berlaku [1]. ADT ini bersifat STATIK [1]. 
Type dalam ADT berisi ADT yang lain [1]. Contohnya ADT waktu terdiri dari ADT JAM dan ADT DATE atau garis yang terdiri dari dua buah ADT POINT [1]. Pasangan dua buah POINT (Top,Left) dan (Bottom,Right) dinamakan SEGI4 [1]. TYPE dapat diterjemahkan sebagai type terdefinisi dalam bahasa yang bersangkutan [1]. Pada konteks prosedural bahasa C, penggunaan struct PRIMITIF dapat diterjemahkan menjadi fungsi atau prosedur [1].
PRIMITIF dapat dikelompokkan menjadi:
#### 1. Konstruktor atau Kreator
Konstruktor atau kreator ini merupakan pembentuk nilai type yang berarti semua variabel bertype tersebut harus melalui konstruktor terlebih dahulu [1]. Biasanya diberi nama Make [1].
#### 2. Selector
Selector digunakan untuk mengakses tipe komponen yang biasanya diberi nama Get [1].
#### 3. Prosedur
Prosedur biasanya digunakan sebagai pengubah nilai komponen yang biasanya diberi nama Get [1].
#### 4. Tipe Validator Komponen
Tipe validator komponen biasanya dipakai untuk mengetes apakah tipe dapat membentuk tipe sesuai dengan batasan yang ada.
#### 5. Deksekutor atau Dealokator
Deksekutor atau dealokator biasanya digunakan untuk menghancurkan nilai varibael sekaligus memori penyimpanannya [1].
#### 6. Baca atau Tulis
Baca atau tulis biasanya digunakan untuk interface dengan input atau output dari device [1].
#### 7. Operator Relasional
Operator relasional biasanya digunakan untuk mendefinisikan tipe yang lebih besar, lebih kecil, sama dengan, dan lain sebagainya [1].
#### 8. Aritmatika
Pada  bahasa C, aritmatika biasanya dipakai hanya untuk variabel yang terdefinisi untuk bilangan numerik [1].
#### 9. Konversi
Biasanya konversi dari tipe tersebut digunakan ke tipe dasar dan sebaliknya [1].

Implementasi ADT biasanya dibagi menajdi dua buah modul utama dan satu modul interface program utama atau driver [1]. Dua modul tersebut diantaranya:
#### 1. Definisi atau Spesifikasi Type dan Primitif atau Header Fungsi (.h)
Biasanya spesifikasi type sesuai dengan kaidah bahasa yang dipakai [1]. Spesifikasi dari primitif juga biasanya diisi sesuai dengan kaidah dalam konteks prosedural yaitu fungsi (diisi dengan nama, domain, range, dan prekondisi) dan prosedur (diisi dengan initial state, final state, dan proses yang dilakukan) [1].
#### 2. Body atau Realisasi dari Primitif (.c)

Konsep ADT dapat diterapkan dengan memisahkan deklarasi type, variabel, dan fungsi dari program ke dalam sebuah file (.h) dan memisahkan definisi fungsi dari program ke dalam file (.cpp) [1].

## Guided
### 1. Mahasiswa
#### a. File mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED //untuk mengecek apakah header sudah dipakai atau belum di folder/direktori ini
#define MAHASISWA_H_INCLUDED //untuk membuat header mahasiswa

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m); //call by reference
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
#### b. File mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```
#### c. File main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "Rata-rata = " << rata2 (mhs);
    return 0;
}
```
penjelasan


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

```C++
kode
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1]()

##### Output 2
![Screenshot Output Unguided 1.2]()

penjelasan

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:
```C++
Type pelajaran <
namaMapel : string
kodeMapel : string
>
function create_pelajaran( namapel : string,
kodepel : string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )
```
Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
Cobalah hasil implementasi ADT pada file “main.cpp”
```C++
using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```
Contoh output hasil:
```
nama pelajaran : Struktur Data
nilai : STD
```

```C++
kode
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2.1]()

penjelasan

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer
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
[1] Tim Asisten Praktikum. (t.t.). Modul 3: Abstrack Data Type (ADT). Telkom University. 
<br>[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.