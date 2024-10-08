// huspeninacv4.cpp: Definuje vstupní bod pro aplikaci.
//

#include "huspeninacv4.h"
using namespace std;

int jePrestupny(int rok) {
	if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
		return 1;
	}
	return 0;
}




int main()
{
	int roky[] = { 1000,2000,2002,2012,2022,2200 };
	int pocetRoku = sizeof(roky) / sizeof(roky[0]);

	for (int i = 0; i < pocetRoku; i++) {
		int rok = roky[i];
		if (jePrestupny(rok)) {
			printf("Rok %d je prestupny.\n", rok);
		}
		else{
			printf("Rok %d neni prestupny.\n", rok);
		
		}
	}
	return 0;
}
