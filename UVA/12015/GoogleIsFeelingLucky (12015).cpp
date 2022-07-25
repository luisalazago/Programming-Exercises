#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int cases, valor, mayor, ver, k, pos;
	string pagina;
	vector<int> valores;
	vector<string> lucky;
	vector<string> paginas;

	cin >> cases;
	k = 1;
	while(cases--) {
		for(int i = 0; i < 10; i++) {
			cin >> pagina >> valor;
			paginas.push_back(pagina);
			valores.push_back(valor);
		}

		mayor = -5000;
		for(int l = 0; l < 10; l++) {
			if(valores[l] > mayor) {
				mayor = valores[l];
				pos = l;
			}
		}
		lucky.push_back(paginas[pos]);
		for(int j = 0; j < 10; j++) {
			if(valores[j] == valores[pos]) {
				ver = 0;
				for(int l = 0; l < 10; l++) if(paginas[j] == paginas[l] && l != j) ver = 1;
				if(ver == 0) lucky.push_back(paginas[j]); 
			}
		}

		int i = 0;
		int j = 0;
		for(vector<string>::iterator it = lucky.begin(); it != lucky.end(); it++, i++) {
			for(vector<string>::iterator jt = lucky.begin(); jt != lucky.end(); jt++, j++) {
				if(*it == *jt && i != j) lucky.erase(jt);
			}
		}

		cout << "Case #" << k << ":" << endl;
		for(int i = 0; i < lucky.size(); i++) cout << lucky[i] << endl;
		paginas.clear();
		valores.clear();
		lucky.clear();
		k++;
	}
	return 0;
}