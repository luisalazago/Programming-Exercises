#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

int n;
vector<vector<pair<int, int>>> adj(50000);
vector<int> p(50000);
vector<int> d(50000);

void inicializar(int s) {
	for(int i = 0; i < n; ++i) {
		d[i] = INT_MAX;
		p[i] = -1;
	}

	d[s] = 0;
}

void dijkstra(int s) {
	int j, u, v, peso, costo;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cola;

	inicializar(s);
	cola.push(make_pair(0, s)); // Se iniciliza el nodo s cómo cero, como se había establecido. (nodo, peso)

	while(!cola.empty()) {
		costo = cola.top().first; // Costo del primer elemento de la cola.
		u = cola.top().second; // Predecesor del elemento.
		cola.pop();

		if(costo == d[u]) { // Con este condicional permite hacer el hecho de actulizar un nodo.
			for(j = 0; j < adj[u].size(); ++j) {
				v = adj[u][j].first; // Elemento con el que está conectado el nodo
				peso = adj[u][j].second; // El peso del elemento.
				if(d[u] != INT_MAX && d[u] + peso < d[v]) { // Se verifica si el elemento ya ha sido modficiado y si se cumple la relajación.
					d[v] = d[u] + peso;
					p[v] = u;
					cola.push(make_pair(d[v], v)); // Se actualiza el elemento relajado.
				}
			}
		}
	}
}

int main() {
	FAST_IO;
	int m, aux1, aux2, peso;

	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> aux1 >> aux2 >> peso;
		adj[aux1].push_back(make_pair(aux2, peso));
	}

	dijkstra(0);

	for(int i = 0; i < n; ++i) cout << "Distancia a nodo " << i << ": " << d[i] << endl;
	for(int i = 0; i < n; ++i) cout << "Predecesor nodo " << i << ": " << p[i] << endl; 

	return 0;
}