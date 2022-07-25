#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

vector<int> divisores(int& numero) {
	int i = 2;
	vector<int> temp;
	while(numero != 1) {
		if(numero % i == 0) {
			temp.push_back(i);
			numero /= i;
		}
		else ++i;
	}

	if(temp.size() > 1) sort(temp.begin(), temp.end());
	return temp;
}

int main() {
	int numero;
	vector<int> temp;
	set<vector<int>> operadores;
	set<vector<int>>::iterator it;

	cin >> numero;
	while(numero) {
		temp = divisores(numero);

		if(temp.size() > 1) {
			operadores.insert(temp);
			temp.clear();
		}
		
		for(it = operadores.begin(); it != operadores.end(); ++it) {
			if((*it).size() > 2) {
				for(int i = 0; i < (*it).size(); ++i) {
					for(int j = 1; j < (*it).size() - i; ++j) {
						temp.push_back((*it)[i] * (*it)[j + i]);
						for(int k = 0; k < (*it).size(); ++k) if(k != i && k != (j + i)) temp.push_back((*it)[k]);
						sort(temp.begin(), temp.end());
						operadores.insert(temp);
						temp.clear();
					}
				}
			}
		}

		cout << operadores.size() << endl;
		for(it = operadores.begin(); it != operadores.end(); ++it) {
			for(int i = 0; i < (*it).size(); ++i) {
				if(i < (*it).size() - 1) cout << (*it)[i] << " ";
				else cout << (*it)[i] << endl;
			}
		}

		operadores.clear();
		cin >> numero;
	}

	return 0;
}