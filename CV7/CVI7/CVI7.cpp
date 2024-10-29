// CVI7.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CVI7.h"
#include "Body2d.h"

#define POCET_BODU 10

using namespace std;

int main()
{
	int body[POCET_BODU][2] = {
		{5, 10}, {-14, 2}, {45, 4}, {-9, 8}, {58, -3}, {47, 5}, {-18, -86}, {75, 7}, {-25, 51}, {17, 98}
	};
	int referencniX, referencniY, kvadrant;

	printf("Zadejte souradnice referencniho bodu (X Y): ");
	scanf("%d %d", &referencniX, &referencniY);

	int nejblizsiIndex = indexNejblizsi(POCET_BODU, body, referencniX, referencniY);
	double prumernaVzd = prumernaVzdalenost(POCET_BODU, body, referencniX, referencniY);

	printf("Nejblizsi bod ma index %d a souradnice (%d, %d)\n", nejblizsiIndex, body[nejblizsiIndex][0], body[nejblizsiIndex][1]);
	printf("Prumerna vzdalenost bodu od referencniho bodu je %.2f\n", prumernaVzd);

	printf("Zadejte kvadrant (1-4): ");
	scanf("%d", &kvadrant);
	BodyVKvadrantu(POCET_BODU, body, referencniX, referencniY, kvadrant);

	return 0;
}
