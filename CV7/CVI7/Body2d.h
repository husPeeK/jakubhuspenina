#pragma once
#include <math.h>

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY);
double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY);
void BodyVKvadrantu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int kvadrant);