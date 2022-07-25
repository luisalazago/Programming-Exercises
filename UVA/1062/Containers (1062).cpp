#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int ver, contador;
	string cadena;
	vector< stack<char> > contenedores;
	stack<char> temp;

	cin >> cadena;
	contador = 0;
	while(cadena != "end") {
		for(int i = 0; i < cadena.size(); i++) {
			if(contenedores.size() == 0) {
				temp.push(cadena[i]);
				contenedores.push_back(temp);
				temp.pop();
			}
			else {
				ver = 1;
				for(int j = 0; j < contenedores.size(); j++) {
					if(contenedores[j].top() >= cadena[i]) {
						contenedores[j].push(cadena[i]);
						ver = 0;
						break;
					}
				}
				if(ver == 1) {
					temp.push(cadena[i]);
					contenedores.push_back(temp);
					temp.pop();
				}
			}
		}

		cout << "Case " << ++contador << ": " << contenedores.size() << endl;
		cin >> cadena;
		contenedores.clear();
	}
	return 0;
}

/*La complejidad de este algritmo es O(n^2), ya que compara los contenedores de los topes
  de cada una de las pilas que hay, por eso mismo cuando se eleva la cantidad de casos al
  cuadrado, que es la complejidad del algritmo, UVA lo acepta porque no se pasa del límite
  que es 10^9.*/
