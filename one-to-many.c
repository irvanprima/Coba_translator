#include <stdio.h>
#include <string.h>

#define MAX_MATKUL 5

struct Dosen {
    int id;
    char nama[50];
    struct MataKuliah *mataKuliah[MAX_MATKUL];
    int numMatkul;
};

struct MataKuliah {
    int id;
    char nama[50];
    struct Dosen *dosenPengajar;
};

int main() {
    struct Dosen dosen;
    struct MataKuliah matkul[MAX_MATKUL];

    dosen.id = 101;
    dosen.numMatkul = 3;

    strcpy(dosen.nama,"pak bambang");
    // strcpy(matkul[0].nama, "WEB-PROGRAMMING 1");
    //otomatis nambah matkul
    for (int i = 0; i < dosen.numMatkul; ++i) {
    sprintf(matkul[i].nama, "WEB-PROGRAMMING %d", i + 1);
}

    for (int i = 0; i < dosen.numMatkul; ++i) {
        matkul[i].id = i + 1;
        // Assign dosen ke setiap mata kuliah
        matkul[i].dosenPengajar = &dosen;
        dosen.mataKuliah[i] = &matkul[i];
    }

    printf("Dosen %s mengajar mata kuliah:\n", dosen.nama);
    for (int i = 0; i < dosen.numMatkul; ++i) {
        printf("- %s\n", dosen.mataKuliah[i]->nama);
    }

    return 0;
}
