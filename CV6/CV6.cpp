// CV6.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CV6.h"
#include <ctype.h>

using namespace std;

//1.funkce počet písmen
int pocetPismen(const char *text) {
	int pocet = 0;
	while (*text) {
		if (isalpha(*text)) {
			pocet++;
		}
		text++;
	}
	return pocet;
}

//2 funkce počet čísel
int pocetCislic(const char *text) {
	int pocet = 0;
	while (*text) {
		if (isdigit(*text)) {
			pocet++;
		}
		text++;
	}
	return pocet;
}

//3 fuknce delky slov
int delkySlov(char* text, int* delky) {
	int ps = 0;
	int d = 0;

	while (*text) {
		if (isalpha(*text)) {
			d++;
		}
		else if (d > 0) {
			delky[ps++] = d;
			d = 0;
		}
		text++;
	}
	if (d > 0) {
		delky[ps++] = d;
	}
	return ps;
}



int main()
{
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. \nAuto Hyundai ix35 ma pres 120 konskych sil.";
	int delky[100];
	int psl;

	psl = delkySlov(text, delky);



	int p = pocetPismen(text);
	int c = pocetCislic(text);

	printf("Testovany text zni: \"%s\"\n", text);
	printf("Pocet pismen je v textu je %d\n", p);
	printf("Pocet cislic je v textu je %d\n", c);
	printf("Pocet slov: %d\n", psl);
	printf("Delky slov: ");
	for (int i = 0; i < psl; i++) {
		printf("%d", delky[i]);
		if (i < psl - 1) {
			printf(", ");
		}
	}
	printf("\n");


	return 0;
}
