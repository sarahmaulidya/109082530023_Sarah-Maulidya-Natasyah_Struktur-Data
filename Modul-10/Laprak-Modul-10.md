# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama) </h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A.  <br/>

#### 1. 
#### 2. 
#### 3. 

### B.  <br/>
#### 1. 
#### 2. 
#### 3. 
#### 4. 
##### a. 
##### b. 

### C.

### D. 

### E. 
#### 1. 
#### 2. 
##### a. 
##### b. 
##### c. 

## Guided
### 1. Rekursif
#### a. File rekursif.h 
```C++
#ifndef REKURSIF_H
#define REKURSIF_H

int pangkat_2(int x);

#endif
```
#### b. File rekursif.cpp
```C++
#include "rekursif.h"

int pangkat_2(int x) {
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x -1);
    }
}
```
#### c. File main.cpp
```C++
#include <iostream>
#include "rekursif.h"

using namespace std;

int main() {
    int x;

    cout << "Menghitung pangkat 2 secara rekursif" << endl;
    cout << "Masukkan nilai x: ";
    cin >> x;

    if (x < 0) {
        cout << "Nilai x harus lebih besar atau sama dengan 0." << endl;
    } else {
        cout << "2^" << x << " = " << pangkat_2(x) << endl;
    }
    return 0;
}
```
Program ini menggunakan fungsi rekursif untuk menghitung perpangkatan 2 berdasarkan nilai x yang dimasukkan pengguna. Fungsi `pangkat_2` memiliki kondisi dasar ketika x bernilai 0, yaitu menghasilkan 1. Jika x lebih dari 0, fungsi akan memanggil dirinya sendiri dengan nilai x dikurangi 1 hingga mencapai kondisi dasar. Hasil akhirnya ditampilkan sebagai nilai 2 pangkat x, sedangkan input negatif akan ditolak.
### 2. 
#### a. File queue.h 
```C++
```
#### b. File queue.h 
```C++
```
#### c. File queue.h 
```C++
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