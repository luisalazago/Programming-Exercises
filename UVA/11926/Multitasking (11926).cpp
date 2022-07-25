#include <iostream>
#include <vector>

using namespace std;

int main() {
	int task, repeating_task, numero, ver, ver2;
	vector<int> temp;
	vector<int> repeticiones;
	vector< vector<int> > intervalos;

	cin >> task >> repeating_task;
	while(task != 0) {
		for(int i = 0; i < task; i++) {
			cin >> numero;
			temp.push_back(numero);
			cin >> numero;
			temp.push_back(numero);
			intervalos.push_back(temp);
			temp.clear();
		}
		for(int i = 0; i < repeating_task; i++) {
			cin >> numero;
			temp.push_back(numero);
			cin >> numero;
			temp.push_back(numero);
			cin >> numero; 
			repeticiones.push_back(numero);
			intervalos.push_back(temp);
			temp.clear();
		}

		ver2 = 0;
		for(int i = 0; i < intervalos.size(); i++) {
			for(int j = 0; j < intervalos[i].size(); j++) {
				ver = 0;
				for(int k = i; k < intervalos.size(); k++) {
					for(int l = 0; l < intervalos[k].size(); l++) {
						if(l == 0) { 
							if((intervalos[i][j] >= intervalos[k][l] && intervalos[i][j] <= intervalos[k][l + 1]) && k != i) ver = 1;
						}
						else { 
							if((intervalos[i][j] == intervalos[k][l] || intervalos[i][j] == intervalos[k][l - 1]) && k != i) ver = 1;
						}
					}
				}
				if(ver) ver2++;
				else {
					ver2 = -1;
					break;
				}
			}
			if(ver2 == -1) break;
		}

		for(int i = 0; i < repeticiones.size(); i++) {
			for(int j = 0; j < intervalos.size(); j++) {
				for(int k = 0; k < intervalos[j].size(); k++) {
					if(k == 0) {
						if(repeticiones[i] >= intervalos[j][k] && repeticiones[i] <= intervalos[j][k + 1]) ver2 = -5;
					}
					else {
						if(repeticiones[i] == intervalos[j][k] || repeticiones[i] == intervalos[j][k - 1]) ver2 = -5;
					}
				}
				if(ver2 == -5) break;
			}
			if(ver2 == -5) break;
		}

		if(ver2 == intervalos.size()) cout << "NO CONFLICT" << endl;
		else cout << "CONFLICT" << endl;

		cin >> task >> repeating_task;
	}
	return 0;
}