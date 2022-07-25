#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cases, numero, ver, ver2, ultimo;
	vector<int> secuencia;

	cin >> cases;
	cout << "Lumberjacks:" << endl;
	while(cases--) {
		for(int i = 0; i < 10; i++) {
			cin >> numero;
			secuencia.push_back(numero);
		}

		ver = ver2 = ultimo = 0;
		for(int i = 0; i < secuencia.size(); i++) {
			if(secuencia[i] < secuencia[i + 1]) { 
				if(ver2 > 0) {
					if(i == 9) break;
					ultimo = 3;
					break;
				}
				ver++;
			}
			else if(secuencia[i] > secuencia[i + 1]) {
				if(ver > 0) {
					if(i == 9) break;
					ultimo = 3;					
					break;
				}
				ver2++;
			}
		}

		if(ultimo == 3) cout << "Unordered" << endl;
		else cout << "Ordered" << endl;
		secuencia.clear();
	}
	return 0;
}