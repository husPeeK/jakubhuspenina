#include "Hudba.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct t_album* prvni = NULL; // Globální ukazatel na první album

void OnAdd() {
    char i[is];
    char n[nazev];
    int rok;

    printf("\nInterpret: ");
    scanf_s("%s", i, is);
    while (getchar() != '\n');
    printf("Název alba: ");
    scanf_s("%s", n, nazev);
    while (getchar() != '\n');
    printf("Rok vydání: ");
    scanf_s("%d", &rok);
    while (getchar() != '\n');

    add(i, n, rok, &prvni);
}

void OnDel() {
    char i[is];
    printf("\nInterpret: ");
    scanf_s("%s", i, is);
    while (getchar() != '\n');
    del(i, &prvni);
}

void ShowAlbums() {
    printf("\nSeznam alb:\n");
    print(prvni);
    getchar();
}

int main() {
    char cmd;
    do {
        system("cls");
        printf("A: Pøidat album\n");
        printf("D: Smazat album\n");
        printf("P: Zobrazit alba\n");
        printf("Q: Konec\n");

        cmd = tolower(getchar());
        while (getchar() != '\n');

        switch (cmd) {
        case 'a':
            OnAdd();
            break;
        case 'd':
            OnDel();
            break;
        case 'p':
            ShowAlbums();
            break;
        }
    } while (cmd != 'q');
    return 0;
}
