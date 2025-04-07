#ifndef LOGIC_H
#define LOGIC_H
#include "list.h"
#define MAKS_KOTA 5

typedef struct {
    char namaKota[20];
    LinkedList daftarNama;
    bool aktif;
} Kota;

extern Kota kotaArray[MAKS_KOTA];
extern int jumlahKota;

void entryData();
void deleteKota();
void deleteNamaDariKota();
void tampilkanData();

#endif