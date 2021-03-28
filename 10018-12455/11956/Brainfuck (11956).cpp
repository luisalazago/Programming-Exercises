#include <iostream>
#include <string>
#include <list>

#define base 16;

using namespace std;

int main() {
	int cases, j, numero, numero2, i;
	list<int> brain;
	list<int> numeros;
	list<int>::iterator it;
	list<int>::iterator jt;
	list<string> resultados;
	list<string>::iterator kt;
	string comandos, resultado;

	cin >> cases;
	j = 1;
	while(cases--) {
		cin >> comandos;
		for(i = 0; i < 100; i++) brain.push_back(0);
		i = 0;
		it = brain.begin();
		while(i < comandos.size()) {
			if(comandos[i] == '>') {
				it++;
				if(*it == 100) it++;
			}
			else if(comandos[i] == '<') {
				it--;
				if(*it == 100) it--;
			}
			else if(comandos[i] == '+') {
				*it += 1;
				if((*it) > 255) *it = 0;
			}
			else if(comandos[i] == '-') {
				*it -= 1;
				if((*it) < 0) *it = 255;
			}
 			i++;
		}

		resultado = "";
		for(it = brain.begin(); it != brain.end(); it++) {
			if((*it) == 0) resultado += "00";
			else{
				numero = numero2 = *it;
				numero /= base;
				numero2 = numero2 % base;
				numeros.push_back(numero2);
				while(numero > 16) {
					numero /= base;
					numero2 = numero;
					numero2 = numero2 % base;
					numeros.push_back(numero2);
				}
				if(numero == 10) resultado += 'A';
				else if(numero == 11) resultado += 'B';
				else if(numero == 12) resultado += 'C';
				else if(numero == 13) resultado += 'D';
				else if(numero == 14) resultado += 'E';
				else if(numero == 15) resultado += 'F';
				else resultado += to_string(numero);
				for(jt = numeros.begin(); jt != numeros.end(); jt++) {
					if((*jt) == 10) resultado += 'A';
					else if((*jt) == 11) resultado += 'B';
					else if((*jt) == 12) resultado += 'C';
					else if((*jt) == 13) resultado += 'D';
					else if((*jt) == 14) resultado += 'E';
					else if((*jt) == 15) resultado += 'F';
					else resultado += to_string(*jt);
				}
			}
			resultados.push_back(resultado);
			resultado = "";
			numeros.clear();
		}

		cout << "Case " << j << ":";
		for(kt = resultados.begin(); kt != resultados.end(); kt++) cout << " " << *kt;
		cout << endl;
		j++;
		resultados.clear();
		brain.clear();
	}
	return 0;
}

/*La complejidad de este algoritmo es O(n), ya que el algoritmo recorre todas las posiciones de
  la lista según los comandos que se le den, además de que la complejidad con la cantidad de 
  casos no sobre pasa el 10^9 que es el límite que acepta UVA.*/