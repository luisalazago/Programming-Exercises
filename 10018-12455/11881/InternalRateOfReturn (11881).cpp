#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int cant_cf, cf;
	double resultado, npv, mayor, menor;
	vector<int> valores;

	cin >> cant_cf;
	while(cant_cf) {
		for(int i = 0; i < cant_cf + 1; i++) {
			cin >> cf;
			valores.push_back(cf);
		}

		mayor = 10000;
		menor = -1;
		resultado = 0;
		int k = 1;
		while(menor <= mayor) {
			resultado = (mayor + menor) / 2;
			npv = 0;
			for(int j = 0; j < cant_cf + 1; j++) npv += valores[j] / pow(1 + resultado, j);
			if(npv > 0) menor = resultado;
			else mayor = resultado;
			k++;
			if(k == 100) break;
		}

		printf("%.2f\n", resultado);

		cin >> cant_cf;
		valores.clear();
	}

	return 0;
}