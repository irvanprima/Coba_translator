#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    int id;
    char nama[50]; 
    struct Dosen *pembimbing;
};

struct Dosen {
    int id;
    char nama[50]; 
    struct Mahasiswa *mahasiswa;
};

int main() {
    struct Mahasiswa mhs;
    struct Dosen dosen;

    mhs.id = 1;
    dosen.id = 101;

    strcpy(mhs.nama,"adi");
    strcpy(dosen.nama,"pak budi");

    // Hubungan one-to-one
    mhs.pembimbing = &dosen;
    dosen.mahasiswa = &mhs;

    printf("Mahasiswa %s memiliki pembimbing %s\n", mhs.nama, dosen.nama);
    printf("Pembimbing %s membimbing mahasiswa %s\n", dosen.nama, mhs.nama);

    return 0;
}
