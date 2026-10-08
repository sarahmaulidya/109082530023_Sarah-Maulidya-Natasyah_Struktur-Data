#ifndef MAHASISWA_H_INCLUDED //untuk mengecek apakah header sudah dipakai atau belum di folder/direktori ini
#define MAHASISWA_H_INCLUDED //untuk membuat header mahasiswa

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m); //call by reference
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED