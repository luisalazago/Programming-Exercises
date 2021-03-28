#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main() {
	int cases, n1, n2, diferencia, entero;
	long double resultado;

	cin >> cases;
	while(cases--) {
		cin >> n1 >> n2;
		diferencia = n2 - n1;
		resultado = (2 * sqrt(4 * diferencia) - 2) / 2;
		entero = resultado;
		if(resultado / entero != 1) resultado++;
		if(resultado < 0) resultado = 0;
		entero = resultado;
		cout << entero << endl;
	}
}