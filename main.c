// File: main.c
#include "logic.h"

int main() {
    int pilihan;
    bool isRunning = true;
    while (isRunning) {
        printf("\nMenu:\n");
        printf("1. Entry data kota dan nama\n");
        printf("2. Delete kota\n");
        printf("3. Delete nama dari kota tertentu\n");
        printf("4. Tampilkan semua data\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                entryData();
                break;
            case 2:
                deleteKota();
                break;
            case 3:
                deleteNamaDariKota();
                break;
            case 4:
                tampilkanData();
                break;
            case 5:
                isRunning = false;
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
