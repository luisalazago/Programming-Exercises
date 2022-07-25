#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

bool backTracking(vector<int>& elementos, int i, int n, int acumulado) {
	if(acumulado == n) return true;
	else if(acumulado > n) return false;
	if(elementos.size() == i) return false;

	return backTracking(elementos, i + 1, n, acumulado) || backTracking(elementos, i + 1, n, acumulado + elementos[i]);
	// Lo toma o no lo toma.
}

int main() {
	int cases, cant_bar, barras, numero, acum, i;
	bool ver;
	vector<int> bax;

	cin >> cases;
	while(cases--) {
		cin >> cant_bar >> barras;
		for(int i = 0; i < barras; i++) {
			cin >> numero;
			bax.push_back(numero);
		}

		acum = i = 0;
		ver = backTracking(bax, i, cant_bar, acum);
		
		if(ver == false) cout << "NO" << endl;
		else cout << "YES" << endl;
		bax.clear();
	}

	return 0;
}