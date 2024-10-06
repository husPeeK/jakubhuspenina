// CMakeProject1.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CMakeProject1.h"

using namespace std;

int main()
{
	float cas, vzd;
	const float rs = 340.0;

	cout << "Zadejte cas v sekundach, za ktery se ozval hrom po blesku: ";
	if (!(cin >> cas)) {
		cout << "Prosim, zadej cislo." << endl;
		return 1;
	}

	vzd = cas * rs;

	cout << "Blesk uhodil cca" << vzd << " metru od vas." << endl;
	return 0;
}
