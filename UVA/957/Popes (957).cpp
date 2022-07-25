#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	int periodo, min, max, cantidad, numero, ver, cantidad1, resultado, temp1, x;
	vector<int> popes;
	vector<int>::iterator it, jt, temp;

	while(cin >> periodo) {
		cin >> cantidad;
		for(int i = 0; i < cantidad; i++) {
			cin >> numero;
			popes.pb(numero);
		}

		temp = popes.begin();
		temp1 = (*temp);
		ver = 1;
		cantidad = cantidad1 = resultado = 0;
		while(ver) {
			it = upper_bound(temp, popes.end(), temp1 + periodo - 1);
			cantidad = it - temp;
			x = (*(it - 1)) - (*temp);

			if(it == popes.end()) cantidad1++;

			if(resultado < cantidad && x < periodo) {
				resultado = cantidad;
				min = (*temp);
				max = (*(it - 1));
			}

			temp++;
			while((*temp) == temp1) temp1++;

			temp1 = (*temp);
			if(cantidad1 == 1) ver = 0;
		}

		cout << resultado << " " << min << " " << max << endl;
		popes.clear();
	}
	return 0;
}