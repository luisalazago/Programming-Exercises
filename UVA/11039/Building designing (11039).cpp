#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

bool compare(int n1, int n2) {
	return abs(n1) < abs(n2);
}

int main() {
	bool f1, f2;
	int cases, p, num, cant_pisos;
	vector<int> pisos;

	cin >> cases;
	while(cases--) {
		cin >> p;
		for(int i = 0; i < p; ++i) {
			cin >> num;
			pisos.push_back(num);
		}

		sort(pisos.begin(), pisos.end(), compare);

		cant_pisos = 1;
		f1 = f2 = false;
		for(int i = p - 1; i > 0; --i) {
			num = pisos[i];
			if(num > 0 and !f1) f1 = true;
			if(f1) {
				if(pisos[i - 1] < 0) {
					++cant_pisos;
					f1 = false;
				}
			}
			else if(num < 0 and !f2) f2 = true;
			if(f2) {
				if(pisos[i - 1] > 0) {
					++cant_pisos;
					f2 = false;
				}
			}
		}

		if(!p) cant_pisos = 0;
		cout << cant_pisos << endl;
		pisos = vector<int>();
	}
	return 0;
}
