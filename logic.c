#include "logic.h"

Kota kotaArray[MAKS_KOTA];
int jumlahKota = 0;

void entryData() {
    if (jumlahKota >= MAKS_KOTA) {
        printf("Sudah mencapai batas maksimum kota.\n");
        return;
    }
    printf("Masukkan nama kota: ");
    scanf("%s", kotaArray[jumlahKota].namaKota);
    initList(&kotaArray[jumlahKota].daftarNama);
    kotaArray[jumlahKota].aktif = true;

    int jumlahNama;
    printf("Masukkan jumlah nama untuk kota %s: ", kotaArray[jumlahKota].namaKota);
    scanf("%d", &jumlahNama);
    for (int j = 0; j < jumlahNama; j++) {
        char nama[20];
        printf("  Masukkan nama ke-%d: ", j+1);
        scanf("%s", nama);
        Node *newNode = createNode(nama);
        insertLast(&kotaArray[jumlahKota].daftarNama, newNode);
    }
    jumlahKota++;
}

void deleteKota() {
    char target[20];
    printf("Masukkan nama kota yang ingin dihapus: ");
    scanf("%s", target);
    for (int i = 0; i < jumlahKota; i++) {
        if (kotaArray[i].aktif && strcmp(kotaArray[i].namaKota, target) == 0) {
            deleteAll(&kotaArray[i].daftarNama);
            kotaArray[i].aktif = false;
            printf("Kota dan semua nama di dalamnya telah dihapus.\n");
            return;
        }
    }
    printf("Kota tidak ditemukan.\n");
}

void tampilkanData() {
    if(jumlahKota == 0) {
        printf("Tidak ada data kota yang tersedia.\n");
        return;
    }
    for (int i = 0; i < jumlahKota; i++) {
        if (kotaArray[i].aktif) {
            printf("Kota: %s\n", kotaArray[i].namaKota);
            printList(&kotaArray[i].daftarNama);
        }
    }
}

void deleteNamaDariKota() {
    char targetKota[20], targetNama[20];
    printf("Masukkan nama kota: ");
    scanf("%s", targetKota);
    printf("Masukkan nama yang ingin dihapus: ");
    scanf("%s", targetNama);

    for (int i = 0; i < jumlahKota; i++) {
        if (kotaArray[i].aktif && strcmp(kotaArray[i].namaKota, targetKota) == 0) {
            deleteAfterValue(&kotaArray[i].daftarNama, targetNama);
            printf("Nama telah dihapus dari kota.\n");
            return;
        }
    }
    printf("Kota tidak ditemukan.\n");
}