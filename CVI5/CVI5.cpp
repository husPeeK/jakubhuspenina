// CVI5.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CVI5.h"
#include "vektorovySoucin.h" //prida

using namespace std;

void soucet(double a[3], double b[3], double c[3]) {
	for (int i = 0; i < 3; i++) {
		c[i] = a[i] + b[i];
	}
}

double velikost(double a[3]) {
	double cis = 0.0;
	for (int i = 0; i < 3; i++) {
		cis += a[i] * a[i];
	}
	return sqrt(cis);
}

double skalarniSoucin(double a[3], double b[3]) {
	double vys = 0.0;
	for (int i = 0; i < 3; i++) {
		vys += a[i] * b[i];
	}
	return vys;
}




int main()
{
	double a[3] = { 1,2,3 };
	double b[3] = { 2,5,8 };
	double c[3];

	printf("Vektor A (3 hodnoty oddelene carkou): 1,2,3\n");
	printf("Vektor B (3 hodnoty oddelene carkou): 2,5,8\n");

	soucet(a, b, c);
	printf("Soucet A + B: (%.6f, %.6f %.6f)\n", c[0], c[1], c[2]);

	double velA = velikost(a);
	printf("velikost A: %.6f\n", velA);

	double skalsAB = skalarniSoucin(a, b);
	printf("skalarni soucin AB: %.6f\n", skalsAB);

	vektorovySoucin(a, b, c);
	printf("vektorovy soucin A x B: (%.6f, %.6f, %.6f)\n", c[0], c[1], c[2]);
	return 0;
}
