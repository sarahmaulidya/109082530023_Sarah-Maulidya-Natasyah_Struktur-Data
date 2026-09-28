# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Sarah Maulidya Natasyah - 109082530023</p>

## Dasar Teori
Bahasa C++ diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories awal tahun 1980-an berdasarkan C ANSI (American National Standard Institute) [1].

### A. Dasar Pemrograman<br/>

#### 1. Struktur program C++
Struktur bahasa C++ selalu dimulai dari deklarasi library #include <iostream>, definisi konstanta, tipe data, variabel, fungsi/prosedur, dan program utama int main()[1]. Elemen-elemen yang digunakan pada bahasa C++ sudah diatur sesuai dengan kaidah agar alur programnya berjalan dengan benar [2].
#### 2. Tipe Data dan Variabel
Sama seperti bahasa pemrograman lain, variabel digunakan untuk menyimpan nilai pada program yang sedang berjalan [1]. Biasanya variabel dideklarasikan seperti tipe_data nama_variabel; contohnya (int a;). Terdapat juga konstanta untuk menyatakan nilai yang selalu tetap [1]. Biasanya untuk mendeklarasikan konstanta, perlu ditambahkan kata const di awal tipe variabel [1].

### B. Input/Output<br/>
Untuk menghasilkan output, perlu menggunakan fungsi cout dengan operator << untuk mencetak data/teks/konstanta/variabel [1]. Sedangkan untuk meminta input dari pengguna menggunakan fungsi cin dengan operator >> [1].

### C. Operator
Operator digunakan untuk melakukan operasi/manipulasi/perhitungan dari variabel yang ada [1]. Terdapat beberapa contoh operator seperti operator aritmatika (+, -, *, /, %), operator assignment, operator logika, operator unary, operator sizeof, operator increment dan decrement[1]. Operator berfungsi untuk memproses suatu logika dalam program [2].

### D. Pemodifikasi Tipe
Biasanya, pemodifikasian tipe ada diawal tipe data kecuali untuk void. Modifikasi tipe data diantaranya unsigned, short, dan long yang biasanya digunakan untuk mengubah jangkauan nilai suatu tipe data [1].

### E. Kondisional
Kondisional biasanya digunakan untuk pengambilan keputusan dalam penyelesaian masalah [1]. Terdapat tiga jenis  kondisi dalam bahasa C++ yaitu if, if-else, dan switch[1]. Jika menggunakan kondisional, program nantinya akan memilih perintah yang akan dikerjakan atau tidak tergantung dengan syarat yang diminta [2]. Berikut bentuk umumnya:
<pre>
if (kondisi) {
    // pernyataan jika benar
} else {
    // pernyataan jika salah
}
</pre>


### F. Perulangan
Perulangan ini merupakan salah satu kelebihan karena digunakan untuk mempersingkat waktu dan meringkas kode dalam mengeksekusi suatu program [1]. Perulangan pada bahasa C++ diantaranya:
#### 1. Perulangan dengan for dan while 
Biasanya digunakan saat kondisi terpenuhi, dan jika tidak maka kondisi akan langsung berhenti[1].
#### 2.	Perulangan dengan do ... while 
Perbedaannya terletak pada proses penyeleksian kondisi di bagian bawah (ada pada while) sehingga perulangan biasanya akan dieksekusi minimal satu kali[1]. 


## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "Input angka pertama: ";
    cin >> angka1;
    cout << "Input angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan " << angka1 << " + " << angka2 << " = " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan " << angka1 << " - " << angka2 << " = " << angka1 - angka2 << endl;
    cout << "Hasil perkalian " << angka1 << " x " << angka2 << " = " << angka1 * angka2 << endl;
   
    if (angka2 != 0) {
        cout << "Hasil pembagian " << angka1 << " / " << angka2 << " = " << angka1 / angka2 << endl;
    } else {
        cout << "Angka kedua tidak boleh 0.";
    }   
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-1.1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-1.2.png?raw=true)

Program ini digunakan untuk menerima input dua buah angka bertipe float dari pengguna. Output program berupa hasil dari penjumlahan, pengurangan, perkalian, dan pembagian dari kedua angka yang diinput pengguna. Di program ini terdapat kondisi if-else pada operasi pembagian untuk memvalidasi angka pembagi agar tidak error karena inputnya nol.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.
Contoh: 79 : tujuh puluh sembilan

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input angka 0-100: ";
    cin >> n;
    
    string kata[] {
        "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };

    if (n >= 0 && n <= 19) {
        cout << n << " : " << kata[n] << endl;
    } else if (n >= 20 && n <= 99) {
        int puluhan = n / 10;
        int satuan = n % 10;

        cout << n << " : " << kata[puluhan] << " puluh";

        if (satuan > 0) {
            cout << " " << kata[satuan];
        }
        cout << endl;
        
    } else if (n == 100) {
        cout << n << " : seratus" << endl;
    } else {
        cout << "Angka harus 0-100." << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-2.1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 2.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-2.2.png?raw=true)

Program ini digunakan untuk menerima input angka dari pengguna yang akan menghasilkan output nilai dari angka tersebut dalam bentuk tulisan. Angka yang bisa diinput hanya angka 0-100. Program ini menggunakan array string untuk menyimpan kata angka dari 0-19. Jika inputnya angka dari rentang 0-19 maka output berupa tulisan yang sesuai dengan indeksnya. Jika inputnya angka dari 20-99, program akan memisahkan angka menjadi puluhan dan satuan menggunakan pembagian dan modulo. Jika inputnya 100, maka program akan langsung menampilkan output "seratus" dan jika inputnya selain 0-100 maka akan menampilkan pesan error. 

### 3. Buatlah program yang dapat memberikan input dan output sbb.
input: 3<br>
output:<br>
<pre>
3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *
</pre>

```C++
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Input: ";
    cin >> a;
    
    cout << "Output: " << endl;

    for (int i = a; i >= 1; i--) {
        for (int s = 0; s < a - i; s++) {
            cout << "  ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }

    for (int s = 0; s < a; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3.1](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-3.1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3.2](https://github.com/sarahmaulidya/109082530023_Sarah-Maulidya-Natasyah_Struktur-Data/blob/main/Modul-1/Output-Unguided-3.2.png?raw=true)

Program ini digunakan untuk menampilkan pola angka mirror dengan tanda * sebagai cerminnya sesuai angka yang diinput oleh pengguna. Program ini menggunakan nested loop untuk menyesuaikan jarak spasi setiap baris agar membentuk pola segitiga terbalik. Loop utama digunakan untuk mengatur jumlah baris. Loop pertama di dalam digunakan untuk membuat spasi. Loop kedua di dalam digunakan untuk menghasilkan output angka yang mundur misal 3 2 1. Loop ketiga digunakan untuk menghasilkan output angka yang maju misal 1 2 3. Loop terakhir (di luar loop utama) digunakan untuk memberikan spasi tanda *.

## Kesimpulan
Dari praktikum yang sudah dilakukan, dapat disimpulkan bahwa sebelum kita mulai mengimplementasikan sebuah program, kita perlu memahami dulu konsep dasar bahasa C++. Contohnya pada unguided 1 diperlukan pemahaman tentang kondisional if-else untuk memvalidasi input agar hasilnya tidak error saat pembagian. Pada unguided 2, penggunaan array juga dapat membantu mempersingkat logika konversi angka. Terakhir, pada unguided 3 program menggunakan perulangan bersarang (nested loop) untuk mengatur pola spasi sesuai angka yang diinput oleh pengguna.

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Telkom University. 
<br>[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.