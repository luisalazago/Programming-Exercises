#include <iostream>
#include <vector>
#include <string>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

set< vector<int> > respuestas;
set< vector<int> >::iterator it;

void backTracking(vector<int>& elementos, vector<int> numeros, int i, int n, int acumulado) {
	if(acumulado == n) {
		respuestas.insert(numeros);
		return;
	}
	else if(acumulado > n) {
		numeros.clear();
		return;
	}
	if(elementos.size() == i) {
		numeros.clear();
		return;
	}

	backTracking(elementos, numeros, i + 1, n, acumulado);
	numeros.push_back(elementos[i]);	
	backTracking(elementos, numeros, i + 1, n, acumulado + elementos[i]); 
}

int main() {
	int numero, num, cantidad;
	vector<int> numeros;
	vector<int> temp;

	cin >> numero >> cantidad;
	while(numero && cantidad) {
		for(int i = 0; i < cantidad; i++) {
			cin >> num;
			numeros.push_back(num);
		}

		cout << "Sums of " << numero << ":" << endl;

		backTracking(numeros, temp, 0, numero, 0);
		if(respuestas.size() > 0) {
			for(it = respuestas.end(); it != respuestas.begin(); it--) {
				if(it == respuestas.end()) it--;
				for(int j = 0; j < (*it).size(); j++) {
					if(j != (*it).size() - 1) cout << (*it)[j] << "+";
					else cout << (*it)[j] << endl;
				} 
			}
			if(respuestas.size() > 1) {
				for(int j = 0; j < (*it).size(); j++) {
					if(j != (*it).size() - 1) cout << (*it)[j] << "+";
					else cout << (*it)[j] << endl;
				}
			}
		}	
		else cout << "NONE" << endl;

		numeros.clear();
		temp.clear();
		respuestas.clear();
		cin >> numero >> cantidad;
	}
	return 0;
}