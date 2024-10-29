#include "Body2d.h"
#include <stdio.h>

//1 fce
int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
	int ni = 0;
	double nvz = sqrt(pow(poleBodu[0][0] - referencniX, 2) + pow(poleBodu[0][1] - referencniY, 2));

	for (int i = 1; i < velikost; i++) {
		double vzd = sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));
		if (vzd < nvz) {
			nvz = vzd;
			ni = i;
		}
	}
	return ni;
}
//2 fce
double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
	double svzd = 0.0;

	for (int i = 0; i < velikost; i++) {
		double vzd = sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));
		svzd += vzd;
	}
	return svzd / velikost;
}
//3 fce
void BodyVKvadrantu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int kvadrant) {
	printf("Body jsou v kvadrantu: %d\n", kvadrant);

	for (int i = 0; i < velikost; i++) {
		int x = poleBodu[i][0] - referencniX;
		int y = poleBodu[i][1] - referencniY;

		if ((kvadrant == 1 && x > 0 && y > 0) ||
			(kvadrant == 2 && x < 0 && y > 0) ||
			(kvadrant == 3 && x < 0 && y < 0) ||
			(kvadrant == 4 && x > 0 && y < 0)) {
			printf("Bod %d: (%d, %d)\n", i, poleBodu[i][0], poleBodu[i][1]);
		}
	}
}

