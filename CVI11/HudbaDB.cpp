#include "Hudba.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add(const char* i, const char* n, int rok, struct t_album** seznam) {
	struct t_album* nove = (struct t_album*)malloc(sizeof(struct t_album));
	if (!nove) {
		printf("Chyba\n");
		return;
	}

	strncpy(nove->i, i, is - 1);
	strncpy(nove->n, n, nazev - 1);
	nove->rok = rok;
	nove->dalsi = NULL;

	struct t_album** aktualni = seznam;
	while (*aktualni && strcmp((*aktualni)->i, i) < 0) {
		aktualni = &(*aktualni)->dalsi;
	}
	nove->dalsi = *aktualni;
	*aktualni = nove;

}

void del(const char* i, struct t_album** seznam) {
	struct t_album** aktualni = seznam;
	while (*aktualni) {
		if (strcmp((*aktualni)->i, i) == 0) {
			struct t_album* keSmazani->dalsi;
			free(keSmazani);
			printf("Album interpreta %s bylo smazano.\n", i);
			return;
		}
		aktualni = &(*aktualni)->dalsi;
	}
	printf("Interpret %s nebyl nalezen.\n", i);
}

void print(const struct t_album* seznam) {
	while (seznam) {
	printf("Interpret: %s, Album: %s, Rok: %d\n", seznam->i, seznam->n, seznam->rok);
	seznam = seznam->dalsi;
	}
}
