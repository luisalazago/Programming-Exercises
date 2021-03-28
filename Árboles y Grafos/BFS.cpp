#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, l, nodo, k, j, m, aux;
	int nodo_incial, nodo_final;

	while(cin >> n) {
		vector<vector<int>> nodos(n);
		cin >> l;
		for(int i = 0; i < l; ++i) {
			cin >> nodo >> k;
			for(int j = 0; j < k; ++j) {
				cin >> aux;
				nodos[nodo].push_back(aux); // Se guarda el elemento en la posición del nodo.
			}
		}

		cin >> nodo_incial >> nodo_final;

		// Implementación

		queue<int> cola;
		vector<int> visitados(12, 0);

		cola.push(nodo_incial);
		visitados[nodo_incial] = 1;
		vector<int> padre(12, -1);
		padre[nodo_incial] = nodo_incial; // Este marca el camino.

		while(!cola.empty()) {
			nodo = cola.front() // Coge el elemento en la punta.
			cola.pop() // Lo quita de la cola.
			if(nodo == nodo_final) break;

			for(int i = 0; i < nodos[nodo]; ++i) {
				aux = nodos[nodo]; // El hijo del nodo.
				if(!visitados[aux]) {
					cola.push(aux); // Se añade el hijo a la cola.
					++visitados[aux]; // Se marca.
					padre[aux] = nodo; // El padre 
				}
			}
		} 
	}

	return 0;
}