# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
### A. Array <br/>
Array adalah kumpulan data yang memiliki nama dan setiap elemennya bertipe data yang sama [1]. Sebuah array juga bisa dideklarasikan sekaligus saat dideklarasikan dengan cara nilai-nilai yang diinisialisasikan ditulis di antara kurung kurawal ```{}``` [2].
#### 1. Array Satu Dimensi
Array satu dimensi adalah array yang hanya terdiri dari satu baris data saja [1]. Umumnya, array datu dimensi ditulis ```tipe_data nama_var[ukuran]```
Dalam bahasa C++, array disimpan dalam memori dengan lokasi yang berurutan [1]. Indeks pertama pada array dimulai dari 0 dan seterusnya  tergantung jumlah ukuran array yang dibuat [1]. Array satu dimensi ini biasanya mewakili bentuk suatu vektor [2].
#### 2. Array Dua Dimensi
Array dua dimensi memiliki bentuk yang seperti tabel yang biasanya digunakan untuk menyimpan data yang terbagi menjadi dua bagian yaitu dimensi pertama dan dimensi kedua [1]. Cara penulisan array ini sebagai berikut.
```
int data_nilai[4][3]; // terdiri dari 4 baris 3 kolom
nilai[2][0] = 10;     //menjelaskan bahwa array yang dimaksud berada pada baris berindeks 2 dan pada kolom berindeks 0.
```
Array dua dimensi biasanya mewakili bentuk suatu matriks atau tabel [2].
#### 3. Array Berdimensi Banyak
Pada dimensi ini, array yang mempunyai indeks lebih dari dua yang biasanya menyatakan dimensi dari array itu sendiri [1]. Array berdimensi banyak ini biasanya dideklararasikan sebagai berikut:
```
tipe_data nama_var[ukuran_1][ukuran_2]...[ukuran_n];
```

### B. Pointer <br/>
#### 1. Data dan Memori
Semua data yang ada digunakan oleh program komputer disimpan di dalam RAM komputer [1]. Memori bisa digambarkan sebagai sebuah array satu dimensi yang mempunyai ukuran sangat besar [1]. Setiap cell memory pasti memiliki indeks atau address sebgai identitasnya [1].

#### 2. Pointer dan Alamat
Pointer adalah dasar dari tipe variabel yang bertipe integer dalam format bilangan heksadesimal yang biasanya digunakan untuk menyimpan alamat memori dari variabel yang lain sehingga pointer bisa mengakses nilai dari variabel yang alamatnya ditunjuk [1]. Pointer biasanya dideklarasikan ```type *nama_variabel;```

#### 3. Pointer dan Array
Array da pointer mempunyai hubungan yanag kuat karena banyak operasi yang bisa dilakukan menggunakan array juga bisa dilakukan menggunakan pointer [1].

#### 4. Pointer dan String
##### a. String
String adalah bentuk dari data yang sering digunakan pada bahasa pemrograman untuk mengolah data/teks/array dari karakter [1].
##### b. Pointer dan String
Pada dasarnya, string adalah array dari kumpulan karakter yang biasanya diakgiri dengan karakter khusus \0 [1]. Pada deklarasi penggunaan array ```( amessage[])``` isi array dapat diubah meski alamat penyimpanannya tetap, tetapi pada deklarasi yang menggunakan pointer ```( *pmessage)``` arah petunjuk alamanya dipindahkan ke mana saja tetapi isi dari teksnya bersifat konstan [1].

### C. Fungsi
Fungsi adalah blok dari kode yang dirancang untuk menjalankan tujuan khusus yang bertujuan agar program menjadi lebih tersruktur dan dapat mengurangi pengulangan/duplikasi kode [1]. Umumnya, fungsi memerlukan masukan berupa parameter yang selanjutnya dioleh oleh fungsi dan menghasilkan sebuah nilai (nilai balik fungsi) [1]. bentuk umum dari fungsi sebagai berikut:
```
tipe_keluaran nama_fungsi(daftar_parameter) {
    blok pernyataan fungsi;
}
```

### D. Prosedure
Dalam bahasa C++, prosedure adalah istilah yang digunakan untuk fungsi yang tidak mengembalikan nilai atau lebih dikenal sebagai fungsi void [1]. Fungsi ini akan melakukan tugas tertentu tetapi tidak mengembalikan nilai kepada pemanggilnya [1]. Bentuk umum prosedure sebagai berikut:
```
void nama_prosedure (daftar_parameter) {
    blok pernyataan prosedure;
}
```

### E. Parameter Fungsi
#### 1. Parameter Formal dan Parameter Aktual
Parameter formal adalah variabel yang ada di daftar parameter saat mendefinisikan fungsi [1]. Contohnya pada kode dibawah, x dan y adalah parameter formal.
```
float perkalian (float x, float y) {
    return (x * y);
}
```

Parameter aktual adalah paramaeter yang tidak selamanya menyataakan variabel yang dipakai untuk memanggil fungsi [1]. Contohnya ada pada kode dibawah ini, a dan b adalah parameter aktual.
```
x = perkalian(a, b);
y = perkalian(20, 30);
```

#### 2. Cara melewatkan Parameter
##### a. Call by Value (Pemanggilan dengan Nilai)
Pada call by value, nilai parameter aktual akan disalin dalam parameter formal, jadi parameter aktual tidak berubah walaupun parameter formalnya berubah [1].

##### b. Call by Pointer (Pemanggilan dengan Pointer)
Call by pointer adalah cara untuk melewatkan alamat suatu variabel ke dalam suatu fungsi [1]. Cara ini bisa mengubah variabel yang ada diluar fungsi [1].
Contoh penulisan call by pointer sebagai berikut:
```
tukar(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    ... ... 
}
```
Cara memanggilnya dengan ```tukar(&a, &b);```


##### c. Call by Reference (Pemanggilan dengan Referensi)
Call by reference berfungsi untuk melewatkan alamat suatu variabel dalam suatu fungsi yang dapat mengubah nilai  variabel aktual yang dilewatkan ke dalam fungsi [1]. Cara ini bisa mengubah variabel yang ada diluar fungsi [1]. Contoh penulisan call by reference sebagai berikut:
```
tukar(int &px, int &py) {
    int temp;
    temp = px;
    px = py;
    py = temp;
    ... ... 
}
```
Cara memanggilnya dengan ```tukar(a, b);```
 
## Guided
### 1. Array Satu Dimensi
```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = "
             << nilai[i] << endl;
    }
    
    return 0;
}
```
Program ini menggunakan array satu dimensi bertipe integer bernama ```nilai``` yang menyimpan lima data angka yaitu 80, 75, 90, 85, 95 dari indeks 0 sampai 4. Di program ini terdapat perulangan ```for``` untuk menampilkan isi array secara berurutan.
### 2. Array Dua Dimensi 
```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;
    return 0;
}
```
Program ini menggunakan array dua dimensi bertipe integer bernama ```nilai``` berukuran 3 x 3 yang menyimpan sembilan data angka dalam bentuk baris dan kolom (matriks). Pada program ini terdapat perulangan ```for``` bersarang yang digunakan untuk menampilkan isi array setiap baris secara berurutan. Setelah mencetak semua nilai array, program juga akan menampilkan nilai spesifik yang berada di baris indeks 1 dan kolom indeks 2 sesuai dengan yang dituliskan pada kode program.
### 3. Array Tiga Dimensi
```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}
```
Program ini menggunakan array tiga dimensi bertipe integer bermana ```data``` berukuran 2 x 2 x 3 yang menyimpan dua belas angka dalam bentuk blok, baris, dan kolom. Program ini langsung menampilkan nilai spesifik yang berada di blok indeks 0, baris indeks 1, dan kolom indeks 2 sesuai dengan yang dituliskan pada kode program.
### 4. Function
```C++
#include <iostream>
using namespace std;

int maks3 (int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max)
        temp_max = b;

    if (c > temp_max)
        temp_max = c;

        return temp_max;
    }

int main() {
        int x, y, z;

        cout << "Masukkan nilai 1: ";
        cin >> x;

        cout << "Masukkan nilai 2: ";
        cin >> y;

        cout << "Masukkan nilai 3: ";
        cin >> z;

        cout << "Nilai maksimum = "
             << maks3(x, y, z);

        return 0;
}
```
Program ini menggunakan fungsi bertama ```maks3``` yang menerima tiga parameter integer untuk mencari nilai terbesar diantaranya dengan cara membandingkan setiap nilai secara berurutan menggunakan logika ```if```. Pada fungsi ```main```, program mendeklarasikan tiga variabel integer, lalu meminta pengguna untuk memasukkan tiga angka secara berurutan. Setelah data diterima, program akan memanggil fungsi maks3 dengan ketiga nilai tersebut sebagai argumen dan menampilkan hasil nilai maksimum yang ditemukan.
### 5. Procedure
```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur Data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Program ini mendefinisikan sebuah fungsi bernama ```sapa``` bertipe void yang berfungsi untuk menampilkan pesan teks "Selamat datang di Praktikum Struktur Data" ke layar. Pada fungsi ```main``` program memanggil fungsi ```sapa()``` tersebut untuk menjalankan perintah percetakan pesan sambutan sebelum program diakhiri.
### 6. Pointer 1 (Alamat pada Variabel)
```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;

    return 0;
}
```
Program ini mendefinisikan fungsi ```main``` yang di dalamnya mendeklarasikan sebuah variabel bertipe integer bernama ```angka``` dengan nilai 100. Selanjutnya, program akan menampilkan nilai dari variabel dan juga alamat memori tempat variabel itu disimpan menggunakan operator ```&```.
### 7. Pointer 2
```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka        : " << angka << endl;    //100
    cout << "Alamat angka       : " << &angka << endl;   //address
    cout << "Isi pointer        : " << pointer << endl;  //address angka
    cout << "Nilai dari pointer : " << *pointer << endl; //value angka (100)

    return 0;
}
```
Program ini digunakan untuk mendeklarasikan sebuah variabel integer bernama angka dengan nilai 100 dan sebuah variabel pointer bernama ```pointer```. pada program ini, alamat memori dari variabel ```angka``` disimpan ke dalam pointer menggunakan operator alamat (```&```). Program akan menampilkan nilai asli dari ```angka```, alamat memori variabel tersebut, isi pointer yang berisi alamat memori yang sama, dan nilai yang ditunjuk oleh pointer menggunakan operator (```*```) untuk menunjukkan bahwa popinter tersebut menunjukkan pada nilai 100.
### 8. Pointer pada Array
```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}
```
Program ini digunakan untuk mendeklarasikan array karakter bernama ```arr``` yang berukuran 6 elemen dan mengisinya dengan karakter tertentu. Program akan mencetak nilai elemen yang ada di indeks 3 dan alamat pada indeks 4 menggunakan operator ```&``` sesuai dengan yang ditulis pada kode.
### 9. Call by Pointer, Reference, Value
```C++
#include <iostream>
using namespace std;

//Call by Pointer
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


// Call by Reference
// #include <iostream>
// using namespace std;

// void tukar(int &x, int &y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     tukar(a, b); 

//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }

// Call by Value
// #include <iostream>
// using namespace std;

// void tukar(int x, int y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     // Memanggil fungsi dengan mengirimkan nilainya saja
//     tukar(a, b);

//     // Hasil print di bawah ini angkanya akan tetap a = 4 dan b = 6
//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }
```
Pada program ini terdapat call by pointer, call by reference, dan call by value. Pada call by pointer, nilai ```a``` dan ```b``` ditukar melalui alamat yang dikirim ke fungsi ```tukar```. Pada call by reference, nilai ```a``` dan ```b``` dapat diubah melalui fungsi, sedangkan pada call by value nilai yang digunakan dalam dungsi hanya berupa salinan sehingga nilai asli tidak berubah.
### 10. Call by Value
```C++
#include <iostream>
using namespace std;

void tukar(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    tukar(a, b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```
Program ini menggunakan konsep call by value melalui fungsi ```tukar``` yang menerima dua parameter integer sebagai salinan nilai. Pada fungsi ```main```, program mencetak nilai awal variabel ```a``` dan ```b``` lalu memanggil fungsi tersebut. Proses pertukaran dalam fungsi tidak mengubah nilai asli dari variabel ```a``` dan ```b``` saat di cetak.
### 11. Call by Pointer
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```
Program ini menggunakan konsep call by pointer melalui fungsi ```tukar``` yang menerima parameter pointer integer. Pada fungsi ```main```, program memanggil fungsi tersebut menggunakan operator ```&```. Pada program ini terdapat proses manipulasi data sehingga nilai variabel ```a``` dan ```b``` ditukar secara permanen saat program dicetak.


## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3!

```C++
#include <iostream>
using namespace std;

const int N = 3;

void inputMatriks(int m[N][N], string nama) {
    cout << "Masukkan nilai " << nama << " (input 3 angka yang dipisahkan oleh spasi)" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Baris-" << i + 1 << " : ";
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
}

void cetakMatriks(int m[N][N], string judul) {
    cout << "\n" << judul << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void tambah(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void kurang(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void kali(int a[N][N], int b[N][N], int c[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    inputMatriks(A, "Matriks A");
    inputMatriks(B, "Matriks B");

    cetakMatriks(A, "Matriks A = ");
    cetakMatriks(B, "Matriks B = ");

    tambah(A, B, C);
    cetakMatriks(C, "Hasil A + B = ");

    kurang(A, B, C);
    cetakMatriks(C, "Hasil A - B = ");

    kali(A, B, C);
    cetakMatriks(C, "Hasil A x B = ");

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-02/Screenshot-Output/Unguided-1/Output-Unguided-1.1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-02/Screenshot-Output/Unguided-1/Output-Unguided-1.2.png?raw=true)

Program ini digunakan untuk menampilkan dua matriks berukuran 3x3 yang diinput oleh pengguna menggunakan array 2 dimensi dan dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3. Dalam program ini terdapat beberapa fungsi. Fungsi ```inputMatriks()``` digunakan untuk menentukan menginput matriks menggunakan perulangan ```for``` agar bisa membaca setiap baris dan kolom. Fungsi ```cetakMatriks``` digunakan pegguna untuk menampilkan isi matriks. Fungsi ```tambah()``` digunakan untuk menjumlahan semua elemen matriks. Fungsi ```kurang()``` digunakan untuk mengurangkakn elemen matriks. Fungsi ```kali()``` digunakan untuk melakukan perkaliain matriks menggunakan perulangan ```for```. Output dari program ini adalah hasil dari keseluruhan operasi. 

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel!

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

void cetak(int a, int b, int c) {
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "-- Call by Pointer --" << endl;
    cout << "Sebelum : ";
    cetak(a, b, c);
    tukarPointer(&a, &b, &c);
    cout << "Sesudah : ";
    cetak(a, b, c);

    a = 10; b = 20; c = 30;

    cout << "\n-- Call by Reference --" << endl;
    cout << "Sebelum : ";
    cetak(a, b, c);
    tukarReference(a, b, c);
    cout << "Sesudah : ";
    cetak(a, b, c);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-02/Screenshot-Output/Unguided-2/Output-Unguided-2.png?raw=true)

Program ini digunakan untuk menukar nilai tigas variabel menggunakan call by pointer dan call by reference. Fungsi ```tukarPointer()``` digunakan untuk menukar nilai tiga variabel menggunakan call by pointer. Fungsi ```tukarReference``` digunakan untuk menukar nilai tiga variabel menggunakan call by reference. Fungsi ```cetak()``` digunakan untuk menampilkan nilai dari variabel ```a```, ```b```, dan ```c```. Pada fungsi ```main()```, nilai awal variabel adalah 10, 20, dan 30 kemudian nilai tersebut ditukar menggunakan call by pointer dan call by reference. Output dari program ini adalah nilai dari variabel sebelum dan sesuah ditukar. 

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini:
--- Menu Program Array ---<br/>
• Tampilkan isi array<br/>
• Cari nilai maksimum<br/>
• Cari nilai minimum<br/>
• Hitung nilai rata-rata<br/>
```C++
#include <iostream>
using namespace std;

int cariMinimum(int *pa, int n);
int cariMaksimum(int *pa, int n);
void hitungRataRata(int *pa, int n);
void tampilkanArray(int *pa, int n);

void tampilkanArray(int *pa, int n) {
    cout << "Isi array : ";
    for (int i = 0; i < n; i++)
        cout << *(pa + i) << " ";
    cout << endl;
}

int cariMinimum(int *pa, int n) {
    int min = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) < min)
            min = *(pa + i);
    }
    return min;
}

int cariMaksimum(int *pa, int n) {
    int maks = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) > maks)
            maks = *(pa + i);
    }
    return maks;
}

void hitungRataRata(int *pa, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + *(pa + i);
    float rata_rata = (float) total / n;
    cout << "Nilai rata-rata = " << rata_rata << endl;
}

int main() {
    int pilihan;
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray(&arrA[0], ukuran);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(&arrA[0], ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(&arrA[0], ukuran) << endl;
                break;
            case 4:
                hitungRataRata(&arrA[0], ukuran);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3.1.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-02/Screenshot-Output/Unguided-3/Output-Unguided-3.1.png?raw=true)
![Screenshot Output Unguided 3.1.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-02/Screenshot-Output/Unguided-3/Output-Unguided-3.2.png?raw=true)

Program ini digunakan untuk mencari nilai minimum, maksimum, dan rata – rata dari array tersebut menggunakan fungsi ```cariMinimum()``` untuk mencari nilai minimum fungsi ```cariMaksimum()``` untuk mencari nilai maksimum, dan prosedur ```hitungRataRata()``` untuk menghitung nilai rata–rata. Pada fungsi ```main()```, terdapat kondisi ```switch-case``` yang digunakan untuk memilih operasi yang ingin dijalankan, seperti menampilkan array, mencari nilai maksimum, mencari nilai minimum, dan menghitung niai rata-rata. Output dari program ini adalah isi array, nilai maksimum, nilai minimum, dan nilai rata-rata sesuai dengan pilihan menu yang dipilih.

## Kesimpulan
Dari praktikum yang sudah dilakukan, dapat disimpulkan bahwa C++ dapat digunakan untuk mengolah data menggunakan array, pointer, function, dan posedure. Array juga dapat digunakan untuk menyimpan data dalam bentuk satu dimensi, dua dimensi, dan dimensi banyak. Sedangkann function dan procedure digunakan untuk menjalankan proses tertentu dalam program. Penggunaan call by pointer dan call by reference sapaat digunakan untuk mengubah nilai variabel tanpa  harus konsep dari acara. Penggunaan beberapa konsep ini juga bisa membantu membuat program menjadi lebih terstruktur dan sesuai dengan kebutuhan.

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Telkom University. 
<br>[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.