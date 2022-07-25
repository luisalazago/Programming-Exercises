#include <iostream>
#include <vector>

using namespace std;

int main() {
	int d, o, mf, sumatoria_poder, fuses, maximo, ver, Sequence;
	vector<int> devices;
	vector<int> operations;
	vector<int> activacion;
	vector<int> amperaje;

	cin >> d >> o >> mf;
	Sequence = 1;
	while(d != 0 && o != 0 && mf != 0) {
		ver = 0;
		devices.push_back(0);
		activacion.push_back(0);
		operations.push_back(0);
		amperaje.push_back(0);
		for(int i = 1; i <= d; i++) {
			cin >> fuses;
			devices.push_back(fuses);
			activacion.push_back(0);
		}
		for(int i = 1; i <= o; i++) {
			cin >> fuses;
			operations.push_back(fuses);
		}

		sumatoria_poder = 0;
		for(int i = 1; i <= o; i++) {
			fuses = operations[i];
			if(activacion[fuses] > 0) {
				sumatoria_poder -= activacion[fuses];
				activacion[fuses] = 0;
			}
			else if(activacion[fuses] == 0) {
				activacion[fuses] = devices[fuses];
			}
			sumatoria_poder += activacion[fuses];
			if(sumatoria_poder > mf) {
				ver = 2;
				break;
			}
			amperaje.push_back(sumatoria_poder);
		}

		cout << "Sequence " << Sequence << endl;
		if(ver == 2) {
			cout << "Fuse was blown." << endl;
			cout << endl;
		}
		else {
			maximo = -9000;
			for(int i = 1; i < amperaje.size(); i++) if(amperaje[i] > maximo) maximo = amperaje[i];
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maximo << " amperes." << endl;
			cout << endl;
 		}
 		amperaje.clear();
 		devices.clear();
 		operations.clear();
 		activacion.clear();
 		Sequence++;
		cin >> d >> o >> mf;
	}
	return 0;
}

/*La complejidad de este algoritmo es O(n), ya que cambia y analiza las operaciones en los elementos
  indicados por las operaciones, pero para esto tiene que recorre todo el vector, además con esta 
  complejidad el algoritmo no pasa de 10^9 que es el límite establecido por UVA.*/