#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	int participantes, presupuesto, cant_hoteles, semanas, menor;
	int numero, cama, suma, ver, pos;
	vector<int> presupuesto_h;
	vector<int> camas; 

	while(cin >> participantes >> presupuesto >> cant_hoteles >> semanas) {
		for(int i = 0; i < cant_hoteles; ++i) {
			cin >> numero;
			presupuesto_h.push_back(numero);
			for(int j = 0; j < semanas; ++j) {
				cin >> cama;
				camas.push_back(cama);
			}
		}

		menor = 100000000;
		ver = 0;
		pos = -1;
		int temp = semanas;
		for(int i = 0; i < cant_hoteles; ++i) {
			suma = 0;
			for(int j = ++pos; j < semanas; ++j) {
				if(camas[j] >= participantes) {
					suma = presupuesto_h[i] * participantes;
					if(suma <= presupuesto) {
						if(suma < menor) menor = suma;
						ver++;
					}
				}
				pos = j;
			} 
			semanas += temp;
		}

		if(!ver) cout << "stay home" << endl;
		else cout << menor << endl;

		presupuesto_h.clear();
		camas.clear();
	}

	return 0;
}