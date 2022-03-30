#include <iostream>
#include <vector>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	int cases, estudiantes, examenes, numero;
	vector<vector<int>> tests;
	vector<vector<int>> bons_abst;

	cin >> cases;
	while(cases--) {
		cin >> estudiantes >> examenes;
		tests = vector<vector<int>>(estudiantes, vector<int>(examenes));
		bons_abst = vector<vector<int>>(estudiantes, vector<int>(2));
		for(int i = 0; i < estudiantes; ++i) {
			for(int j = 0; j < examenes; ++i) {
				cin >> numero;
				tests[i][j] = numero;
			}
			cin >> numero;
			bons_abst[i][0] = numero;
			cin >> numero;
			bons_abst[i][1] = numero;
		}

		
	}

	return 0;
}