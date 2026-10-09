# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT) </h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A. Abstract Data Type (ADT)<br/>
ADT adalah sebuah TYPE yang punya sekumpulan PRIMITIF (operasi dasar) untuk TYPE itu [1]. Pada ADT yang lengkap, terdapat definisi invarian dari TYPE dan aksioma yang berlaku [1]. ADT ini bersifat STATIK [1]. 
Type dalam ADT berisi ADT yang lain [1]. Contohnya ADT waktu terdiri dari ADT JAM dan ADT DATE atau garis yang terdiri dari dua buah ADT POINT [1]. Pasangan dua buah POINT (Top,Left) dan (Bottom,Right) dinamakan SEGI4 [1]. TYPE dapat diterjemahkan sebagai type terdefinisi dalam bahasa yang bersangkutan [1]. Di bahasa C, TYPE ditulis menggunakan struct, sedangkan PRIMITIF dalam konteks prosedural diterjemahkan menjadi fungsi atau prosedur. [1].
PRIMITIF dapat dikelompokkan menjadi:
#### 1. Konstruktor atau Kreator
Konstruktor atau kreator ini merupakan pembentuk nilai type yang berarti semua variabel bertype tersebut harus melalui konstruktor terlebih dahulu [1]. Biasanya diberi nama Make [1].
#### 2. Selector
Selector digunakan untuk mengakses tipe komponen yang biasanya diberi nama Get [1].
#### 3. Prosedur
Prosedur biasanya digunakan sebagai pengubah nilai komponen yang biasanya diberi nama Set [1].
#### 4. Tipe Validator Komponen
Tipe validator komponen biasanya dipakai untuk mengetes apakah tipe dapat membentuk tipe sesuai dengan batasan yang ada [1].
#### 5. Destruktor atau Dealokator
Destruktor atau dealokator biasanya digunakan untuk menghancurkan nilai variabel sekaligus memori penyimpanannya [1].
#### 6. Baca atau Tulis
Baca atau tulis biasanya digunakan untuk interface dengan input atau output dari device [1].
#### 7. Operator Relasional
Operator relasional biasanya digunakan untuk mendefinisikan tipe yang lebih besar, lebih kecil, sama dengan, dan lain sebagainya [1].
#### 8. Aritmatika
Aritmatika di bahasa C hanya terdefinisi untuk bilangan numerik, jadi untuk type buatan sendiri perlu dibuatkan operasi aritmatikanya [1].
#### 9. Konversi
Biasanya konversi dari tipe tersebut digunakan ke tipe dasar dan sebaliknya [1].

Implementasi ADT biasanya dibagi menjadi dua buah modul utama dan satu modul interface program utama atau driver [1]. Dua modul tersebut di antaranya:
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
### Penjelasan
#### a. File mahasiswa.h
File ```mahasiswa.h``` adalah file header yang digunakan untuk mendeklarasikan struktur dari data mahasiswa dengan prosedur ```inputMhs()``` dan fungsi ```rata2()``` yang akan digunakan dalam program.
#### b. File mahasiswa.cpp
File ```mahasiswa.cpp``` berisi kode untuk menjalankan prosedur dan fungsi yang telah dideklarasikan pada file header. Prosedur ```inputMhs()``` digunakan untuk memasukkan data mahasiswa, sedangkan fungsi ```rata2()``` digunakan untuk menghitung nilai rata-rata dari dua nilai mahasiswa.
#### c. File main.cpp
File ```main.cpp``` adalah file utama yang digunakan untuk menjalankan program dan berfungsi untuk memanggil prosedur ```inputMhs()``` untuk menerima data mahasiswa, kemudian memanggil fungsi ```rata2()``` untuk menghitung dan menampilkan hasil rata-ratanya.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.
#### a. File mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED 

struct mahasiswa {
    char nama[50];
    char nim[15];
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(mahasiswa m);
void inputMahasiswa(mahasiswa &m);
void outputMahasiswa(mahasiswa m);

#endif
```
#### b. File mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void inputMahasiswa(mahasiswa &m) {
    cout << "Nama (Input tanpa menggunakan spasi): ";
    cin >> m.nama;
    cout << "NIM: ";
    cin >> m.nim;
    cout << "Nilai UTS: ";
    cin >> m.uts;
    cout << "Nilai UAS: ";
    cin >> m.uas;
    cout << "Nilai Tugas: ";
    cin >> m.tugas;

    m.nilaiAkhir = hitungNilaiAkhir(m);
}

void outputMahasiswa(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "Nilai UTS   : " << m.uts << endl;
    cout << "Nilai UAS   : " << m.uas << endl;
    cout << "Nilai Tugas : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}
```
#### c. File main.cpp
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-03/Screenshot_Output/Unguided-1/Output-Unguided-1.1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-03/Screenshot_Output/Unguided-1/Output-Unguided-1.2.png?raw=true)

### Penjelasan
#### a. File mahasiswa.h
File ```mahasiswa.h``` adalah file header yang digunakan untuk mendeklarasikan data ```mahasiswa``` yang berisi nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir. Pada file ini terdapat fungsi ```hitungNilaiAkhir()```, prosedur ```inputMahasiswa()```, dan prosedur ```outputMahasiswa()```.
#### b. File mahasiswa.cpp
File ```mahasiswa.cpp``` berisi kode dari fungsi dan prosedur yang sudah dideklarasikan pada file header. Terdapat fungsi ```hitungNilaiAkhir()``` yang digunakan untuk menghitung nilai akhir berdasarkan rumus yang sudah ditentukan. Prosedur ```inputMahasiswa()``` digunakan untuk memasukkan data mahasiswa, sedangkan ```outputMahasiswa()``` digunakan untuk menampilkan data mahasiswa dengan nilai akhirnya.
#### c. File main.cpp
File ```main.cpp``` adalah file utama yang digunakan untuk menjalankan program. Pada file ini terdapat sebuah array ```mhs``` yang bisa menyimpan maksimal 10 data mahasiswa. Program akan meminta pengguna menginput jumlah mahasiswa, kemudian menerima data setiap mahasiswa melalui perulangan ```for```. Setelah semua data diinput, program akan menampilkan data mahasiswa lengkap dengan nilai akhirnya.

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

#### a. File pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
#### b. File pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
#### c. File main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-03/Screenshot_Output/Unguided-2/Output-Unguided-2.png?raw=true)

### Penjelasan
#### a. File pelajaran.h
File ```pelajaran.h``` adalah file header yang digunakan untuk mendeklarasikan struktur data ```pelajaran``` yang berisi ```namaMapel``` dan ```kodeMapel```. Pada file ini juga terdapat deklarasi fungsi ```create_pelajaran()``` dan prosedur ```tampil_pelajaran```.
#### b. File pelajaran.cpp
File ```pelajaran.cpp``` berisi implementasi dari fungsi dan prosedur yang ada pada file header. Fungsi ```create_pelajaran()``` digunakan untuk mengisi data nama dan kode mata pelajaran, sedangkan prosedur ```tampil_pelajaran``` digunakan untuk menampilkan mata pelajaran dan kode mata pelajaran.
#### c. File main.cpp
File ```main.cpp``` adalah file utama yang digunakan untuk menjalankan program. Pada file ini terdapat variabel ```namapel``` dan ```kodepel``` yang diisi dengan nama dan kode mata pelajaran. Selanjutnya, pada fungsi ```create_pelajaran()``` dipanggil untuk membentuk data ```pelajaran```, kemudian prosedur ```tampil_pelajaran()``` dipanggil untuk menampilkan hasilnya.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer
#### a. File array.h
```C++
#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

void tampilArray(int arr[3][3]);
void tukarArray(int A[3][3], int B[3][3],
                int barisA, int kolomA,
                int barisB, int kolomB);
void tukarPointer(int *p1, int *p2);

#endif
```
#### b. File array.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3],
                int barisA, int kolomA,
                int barisB, int kolomB) {
        int temp;
        
        temp = A[barisA][kolomA];
        A[barisA][kolomA] = B[barisB][kolomB];
        B[barisB][kolomB] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
#### c. File main.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {11, 22, 33},
        {44, 55, 66},
        {77, 88, 99}
    };

    int x = 20;
    int y = 30;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar: " << endl;
    tampilArray(A);

    cout << "\nArray B sebelum ditukar: " << endl;
    tampilArray(B);

    tukarArray(A, B, 0, 0, 1, 1);

    cout << "Array A setelah ditukar: " << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar: " << endl;
    tampilArray(B);

    cout << "\nSebelum pointer ditukar: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah pointer ditukar: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-03/Screenshot_Output/Unguided-3/Output-Unguided-3.png?raw=true)

### Penjelasan
#### a. File array.h
File ```array.h``` adalah file header yang digunakan untuk mendeklarasikan prosedur ```tampilArray()```, ```tukarArray()```, dan ```tukarPointer()``` yang akan digunakan di dalam program.
#### b. File array.cpp
File ```array.cpp``` berisi implementasi dari prosedur yang sudah dideklarasikan pada file header. Prosedur ```tampilArray()``` digunakan untuk menampilkan isi array 2D, sedangkan ```tukarArray()``` digunakan untuk menukarkan nilai pada posisi tertentu dari dua array. Prosedur ```tukarPointer()``` digunakan untuk menukar nilai dari dua variabel yang ditunjuk oleh pointer.
#### c. File main.cpp
File ```main.cpp``` adalah file utama yang digunakan untuk menjalankan program. Pada file ini terdapat dua array 2D berukuran 3 x 3 dan dua pointer integer yang menunjuk ke variabel ```x``` dan ```y```. Program akan menampilkan isi kedua array, menukarkan nilai pada posisi yang sudah ditentukan, lalu menampilkan kembali isi dari array setelah ditukar. Selain itu, program juga akan menampilkan nilai ```x``` dan ```y``` sebelum dan sesudah proses pertukaran menggunakan pointer.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa ADT dapat digunakan untuk mengelola data dan operasi secara terstruktur dengan memisahkan deklarasi, implementasi, dan program utama. Penerapan ADT dilakukan dengan memisahkan deklarasi pada file header (```.h```), implementasi fungsi atau prosedur pada file (```.cpp```), dan memanggilnya melalui file (```main.cpp```). Selain itu, ADT juga dapat digunakan untuk mengolah data mahasiswa, menyimpan mata pelajaran, dan melakukan pertukaran nilai pada array dan variabel menggunakan pointer.

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 3: Abstract Data Type (ADT). Telkom University. 