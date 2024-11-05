#include "Huspenina.h"

using namespace std;

int prunik(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec) {
	
	if (zacatek1 > konec1) {
		double t = zacatek1;
		zacatek1 = konec1;
		konec1 = t;
	}
	if (zacatek2 > konec2) {
		double t = zacatek2;
		zacatek2 = konec2;
		konec2 = t;
	}
	
	if (zacatek1 > zacatek2) {
		double tz = zacatek1;
		double tk = konec1;

		zacatek1 = zacatek2;
		konec1 = konec2;
		zacatek2 = tz;
		konec2 = tk;
	}
	
	if (konec1 < zacatek2 || konec2 < zacatek1) {
		return 0;
	}
		*vysl_zacatek = (zacatek1 > zacatek2) ? zacatek1 : zacatek2;
		*vysl_konec = (konec1 < konec2) ? konec1 : konec2;

		return 1;

	
}




int main()
{
	double zacatek1, konec1, zacatek2, konec2;
	double vysl_konec, vysl_zacatek;

	printf("Zadejte zacatek a konec prvniho intervalu: ");
	scanf("%lf %lf", &zacatek1, &konec1);

	printf("Zadejte zacatek a konec druheho intervalu: ");
	scanf("%lf %lf", &zacatek2, &konec2);

	if (prunik(zacatek1, konec1, zacatek2, konec2, &vysl_zacatek, &vysl_konec)) {
		printf("Prunik intervalu je: (%.2f, %.2f)\n", vysl_zacatek, vysl_konec);
	}else {
		printf("Nema prunik\n");
	}
	



	return 0;
}