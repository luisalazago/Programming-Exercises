#include <iostream>
#include <vector>
#include <stdio.h>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	int cases, pos, len;
	char temp[2];
	double numero;
	vector<int> posiciones;
	vector<double> numeros;

	cin >> cases;
	while(cases--) {
		len = 0;
		scanf("%d%c", &pos, temp);
		while(temp[0] != '\n') {
			len++;
			posiciones.push_back(pos);
			scanf("%d%c", &pos, temp);
		}

		for(int i = 0; i < len; i++) {
			cin >> numero;
			numeros.push_back(numero);
		}

		int menor = 100000000;
		double temp;
		for(int i = 0; i < posiciones.size(); i++) {
			for(int j = 0; j < posiciones.size(); j++) {
				if(posiciones[i] < posiciones[j]) {
					temp = posiciones[i];
					posiciones[i] = posiciones[j];
					posiciones[j] = temp;
					temp = numeros[i];
					numeros[i] = numeros[j];
					numeros[j] = temp; 
				}
			}
		}

		for(int i = 0; i < numeros.size(); i++) cout << numeros[i] << endl;
		numeros.clear();
		numeros.size();  
	}

	return 0;
}