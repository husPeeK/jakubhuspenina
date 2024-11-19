// CVI10.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CVI10.h"

using namespace std;

void pdslov(FILE *inputFile, FILE *outputFile) {
	int d = 0;
	int prvni = 1;
	char c;

	//precte soubor
	while ((c = fgetc(inputFile)) != EOF) {
		if (isalpha(c) || isdigit(c)) {
			d++;
		}
		else {
			if (d > 0) {
				if (!prvni) {
					printf(",");
					fprintf(outputFile, ",");
				}
				printf("%d", d);
				fprintf(outputFile, "%d", d);
				d = 0;
				prvni = 0;
			}
		}
	}
	//zpracovaní prvniho slova
	if (d > 0) {
		if (!prvni) {
			printf(",");
			fprintf(outputFile, ",");
		}
		printf("%d", d);
		fprintf(outputFile, "%d", d);
	}
}

int main()
{
	FILE* inputFile, * outputfile;
	char c;
	int letterCount = 0;
	int digitCount = 0;

	//otevreni
	inputFile = fopen("..\\..\\..\\huspenina.txt","r");
	if (inputFile == NULL) {
		printf("Chyba\n");
		return 1;
	}
	// cteni
	while ((c = fgetc(inputFile)) != EOF) {
		if (isalpha(c)) {
			letterCount++;
		}
		else if (isdigit(c)) {
			digitCount++;
		}
	}
	//zavreni souboru
	fclose(inputFile);

	//vypis
	printf("Pocet pismen: %d\n", letterCount);
	printf("Pocet cisel: %d\n", digitCount);

	//otevreni vystupniho
	outputfile = fopen("..\\..\\..\\huspeninavystup.txt", "w");
	if (outputfile == NULL) {
		printf("Chyba u vystupu\n");
		return 1;
	}

	//zapis
	fprintf(outputfile, "Pocet pismen: %d\n", letterCount);
	fprintf(outputfile, "Pocet cisel: %d\n", digitCount);


	//2bod
	fseek(inputFile, 0, SEEK_SET);

	printf("Delky slov: ");
	fprintf(outputfile, "Delky slov: ");
	pdslov(inputFile, outputfile);
	printf("\n");
	fprintf(outputfile, "\n");

	//zavreni souboru
	fclose(inputFile);
	fclose(outputfile);
	return 0;
}
