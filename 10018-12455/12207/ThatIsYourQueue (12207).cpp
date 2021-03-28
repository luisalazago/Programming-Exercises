#include <iostream>
#include <deque>

using namespace std;

int main() {
	int persons, cant_commands, j;
	long long contador;
	char comandos[3];
	deque<long long> personas;
	deque<long long>::iterator it;

	cin >> persons >> cant_commands;
	j = 0;
	while(persons != 0 && cant_commands != 0) {
		for(int i = 1, contador = 1; i <= persons && i <= 1000; i++, contador++) personas.push_back(contador);
		cout << "Case " << ++j << ":" << endl; 
		for(int i = 0; i < cant_commands; i++) {
			cin >> comandos;
			if(comandos[0] == 'N') {
				contador = personas.front();
				personas.pop_front();
				personas.push_back(contador);
				cout << contador << endl;
			}
			else {
				cin >> contador;
				for(it = personas.begin(); it != personas.end(); it++) {
					if(*it == contador) {
						personas.erase(it);
						break;
					}
				}
				personas.push_front(contador);
			}
		}

		personas.clear();
		cin >> persons >> cant_commands;
	}
	return 0;
}

/*La complejidad de este algoritmo en el peor de los casos es O(n), ya que tiene que recorre toda la
  cola buscando el elementos para poner al frente. En el mejor de los casos la complejidad de este
  algoritmo es O(1), ya que solamente quita el elemento del frente y lo pone atrás de la cola.

  En cualquiera de los casos la complejidad del algoritmo no sobrepasa el 10^9, que es el límite esta-
  blecido por UVA.*/