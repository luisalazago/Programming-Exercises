#include <iostream>
#include <vector>

using namespace std;

int NOD(int n) {
	int numero = 0;
	for(int i = 1; i <= n; i++) if(n % i == 0) numero++;
	return numero;
}

int main() {
	int cases, a, b, numero, suma;
	vector<int> lista;

	cin >> cases;
	while(cases--) {
		cin >> a >> b;
		lista.push_back(1);
		suma = 0;
		int j = a;
		for(int i = 0; suma < b; i++) {
			// cout << "++" << j << endl;
			numero = NOD(j);
			suma = j + numero;
			lista.push_back(suma);
			j = suma;
		}
		cout << "Vector: ";
		for(int i = 0; i < lista.size(); i++) cout << lista[i] << ", ";
		cout << endl;
		cout << "//" << lista.size() << endl;
		lista.clear();
	}

	return 0;
}