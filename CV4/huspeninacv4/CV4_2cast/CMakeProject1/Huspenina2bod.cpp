// CMakeProject1.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CMakeProject1.h"
using namespace std;

int isPrime(int c1) {
	if (c1 < 0 || c1 > 100) {
		return -1;
	}

	if (c1 == 0 || c1 == 1) {
		return 0;
	}

	for (int i = 2; i * i <= c1; i++) {
		if (c1 % i == 0) {
			return 0;
		}
	}
	return 1;
}


int main()
{
	int tc[] = { 1, 87, 9, 10, 23, 100, 102, 99, 45, -7 };
	int pc = sizeof(tc) / sizeof(tc[0]);

	for (int i = 0; i < pc; i++) {
		int c = tc[i];
		int v = isPrime(c);

		if (v == -1) {
			printf("Cislo %d je mimo interval 0-100\n", c);
		}
		else if (v == 1) {
			printf("Cislo %d je prvocislo\n", c);
		}
		else {
			printf("Cislo %d neni prvocislo\n", c);
		}
	}
	return 0;
}
