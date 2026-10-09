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