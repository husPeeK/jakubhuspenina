// CVI9.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CVI9.h"

using namespace std;

typedef enum {
	soucet = 1,
	skalarniSoucin,
	vektorovySoucin
} typOperace;

typedef enum {
	osaX = 1,
	osaY,
	osaZ
} typOsy;

typedef struct {
	double x;
	double y;
	double z;
} vector3d;

vector3d operace(vector3d u, vector3d v, typOperace typ) {
	vector3d result;
	switch (typ) {
	case soucet:
		result.x = u.x + v.x;
		result.y = u.y + v.y;
		result.z = u.z + v.z;
		break;
	case skalarniSoucin:
		result.x = u.x * v.x + u.y * v.y + u.z * v.z;
		result.y = 0;
		result.z = 0;
		break;
	case vektorovySoucin:
		result.x = u.y * v.z - u.z * v.y;
		result.y = u.z * v.x - u.x * v.z;
		result.z = u.x * v.y - u.y * v.x;
	}
	return result;
}

void rotuj(vector3d* vec, typOsy osa) {
	double t;
	switch (osa) {
	case osaX:
		t = vec->y;
		vec->y = -vec->z;
		vec->z = t;
		break;
	case osaY:
		t = vec->x;
		vec->x = vec->z;
		vec->z = -t;
		break;
	case osaZ:
		t = vec->x;
		vec->x = -vec->y;
		vec->y = t;
		break;
	}
}



void tisk(vector3d u) {
	double vel = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
	printf("v = {x = %.3f, y = %.3f, z = %.3f} |v| = %.3f\n", u.x, u.y, u.z, vel);
}



int main()
{
	vector3d u, v, vysledek;
	int operaceTyp, osaTyp;

	printf("Zadej vektor u (x, y, z oddeluj carkou): ");
	scanf("%lf,%lf,%lf", &u.x, &u.y, &u.z);

	printf("Zadej vektor v (x, y, z oddeluj carkou): ");
	scanf("%lf,%lf,%lf", &v.x, &v.y, &v.z);

	printf("Zadej operaci (1 = soucet, 2 = skalarni soucin, 3 = vektorovy soucin): ");
	scanf("%d", &operaceTyp);

	vysledek = operace(u, v, (typOperace)operaceTyp);
	tisk(vysledek);

	printf("Zadej osu rotace (1 = osa X, 2 = osa Y, 3 = osa Z): ");
	scanf("%d", &osaTyp);

	rotuj(&u, (typOsy)osaTyp);
	printf("Vektor u po rotaci: ");
	tisk(u);
	return 0;
}
