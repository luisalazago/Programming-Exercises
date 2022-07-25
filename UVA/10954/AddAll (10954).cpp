#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int cant_sum, numero, sumatoria, resultado, temp;
	priority_queue<int, vector<int>, greater<int> > numeros;

	cin >> cant_sum;
	while(cant_sum != 0) {
		for(int i = 0; i < cant_sum; i++) {
			cin >> numero;
			numeros.push(numero);
		}

		sumatoria = resultado = 0;
		while(numeros.size() > 1) {
			sumatoria = numeros.top();
			numeros.pop();
			sumatoria += numeros.top();
			numeros.pop();
			resultado += sumatoria;
			numeros.push(sumatoria);
		}

		cout << resultado << endl;
		if(numeros.size() > 0) while(!numeros.empty()) numeros.pop();
		cin >> cant_sum;
	}

	return 0;
}