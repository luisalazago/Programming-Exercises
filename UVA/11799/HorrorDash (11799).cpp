#include <iostream>

using namespace std;

int main() {
	int cases, num_payasos, numero, mayor, j;
	int payasos[10000];

	j = 1;
	cin >> cases;
	while(cases--) {
		cin >> num_payasos;
		for(int i = 0; i < num_payasos; i++) {
			cin >> numero;
			payasos[i] = numero;
		}

		mayor = -5000;
		for(int i = 0; i < num_payasos; i++) if(payasos[i] > mayor) mayor = payasos[i];

		cout << "Case " << j << ": " << mayor << endl;
		j++;
	}

	return 0;
}