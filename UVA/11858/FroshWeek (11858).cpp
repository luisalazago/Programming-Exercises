#include <iostream>
#include <vector>

using namespace std;

int main() {
	int estudiantes, contador, estudiante, minimo, temp;
	vector<int> swaps;

	while(cin >> estudiantes) {
		contador = 0;
		swaps.push_back(0);
		for(int i = 1; i <= estudiantes; i++) {
			cin >> estudiante;
			swaps.push_back(estudiante);
		}

		for(int i = estudiantes; i > 0; i--) {
			for(int j = 1; j <= i; j++) {
				minimo = swaps[j];
				int k = j / 2;
				while(k > 0 && swaps[k] < minimo) {
					swaps[j] = swaps[k];
					j = k;
					k /= 2;
					contador++;
				}
				swaps[j] = minimo;
			}
			temp = swaps[1];
			swaps[1] = swaps[i];
			swaps[i] = temp;	
		}
		cout << "orden: " << endl;
		for(int i = 1; i <= estudiantes; i++) {
			cout << swaps[i] << endl;
		}

		cout << contador << endl;
		swaps.clear();
	} 
	return 0;
}