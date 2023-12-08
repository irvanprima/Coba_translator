#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 10
#define MAX_MATKUL 10

struct Mahasiswa {
    int id;
    char nama[50];
    struct MataKuliah *mataKuliah[MAX_MATKUL];
    int numMatkul;
};

struct MataKuliah {
    int id;
    char nama[50];
    struct Mahasiswa *mahasiswa[MAX_MAHASISWA];
    int numMahasiswa;
};

int main() {
    struct Mahasiswa mhs[MAX_MAHASISWA];
    struct MataKuliah matkul[MAX_MATKUL];

    strcpy(mhs[0].nama, "ASEP 1");
    strcpy(matkul[0].nama, "PEMROGRAMAN-DESKTOP 1");

    // Inisialisasi data mahasiswa
    for (int i = 0; i < MAX_MAHASISWA; ++i) {
        mhs[i].id = i + 1;
        mhs[i].numMatkul = 4; // Misalnya setiap mahasiswa mengambil 4 mata kuliah

        //otomasi asep
        sprintf(mhs[i].nama, "ASEP %d", i + 1);
    }

    // Inisialisasi data mata kuliah
    for (int i = 0; i < MAX_MATKUL; ++i) {
        matkul[i].id = i + 1;
        matkul[i].numMahasiswa = 3; // Misalnya setiap mata kuliah diambil oleh 3 mahasiswa

        //otomasi matkul
        sprintf(matkul[i].nama, "PEMROGRAMAN-DESKTOP %d", i + 1);
    }

    // Menghubungkan mahasiswa dengan mata kuliah (many-to-many)
    for (int i = 0; i < MAX_MAHASISWA; ++i) {
        for (int j = 0; j < mhs[i].numMatkul; ++j) {
            mhs[i].mataKuliah[j] = &matkul[j];
            matkul[j].mahasiswa[i] = &mhs[i];
        }
    }

    // Contoh pencetakan hubungan
    for (int i = 0; i < MAX_MATKUL; ++i) {
        printf("Mata Kuliah %s diambil oleh:\n", matkul[i].nama);
        for (int j = 0; j < matkul[i].numMahasiswa; ++j) {
            printf("- %s\n", matkul[i].mahasiswa[j]->nama);
        }
    }

    return 0;
}
