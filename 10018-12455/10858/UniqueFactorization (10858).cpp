#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cases, numero, divisor, resultado;
	vector<int> numeros;
	vector<int> valores;
	vector<int> temp;
	vector< vector<int> > resultados;

	cin >> cases >> numero;
	while(numero != 0) {
		numeros.push_back(numero);
		cin >> numero;
	}

	for(int i = 0; i < cases; i++) {
		resultado = numeros[i];
		divisor = 2;
		while(divisor <= resultado) {
			if(resultado % divisor == 0) {
				resultado /= divisor;
				valores.push_back(divisor);
			}
			else divisor++;
		}
		if(valores.size() == 0) cout << 0 << endl;
		else {
			for(int i = 0; i < valores.size(); i++) {
				
			}
		}
	}
	return 0;
}