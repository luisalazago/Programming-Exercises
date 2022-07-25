#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define endl '\n'
#define INFINITO 20000000

using namespace std;

bool recorridoEspacio(vector<vector<pair<int, int>>>& agujeros, vector<bool>& en_cola, vector<int>& conteo, vector<int>& holes_weight,int wormholes) {
	int estrella, peso, actual_star;
	queue<int> cola;

	cola.push(0);
	en_cola[0] = true;
	holes_weight[0] = 0;
	while(!cola.empty()) {
		estrella = cola.front();
		cola.pop();
		en_cola[estrella] = false;

		for(int i = 0; i < agujeros[estrella].size(); ++i) {
			actual_star = agujeros[estrella][i].first;
			peso = agujeros[estrella][i].second;
			if(holes_weight[estrella] != INFINITO && holes_weight[estrella] + peso < holes_weight[actual_star]) {
				holes_weight[actual_star] = holes_weight[estrella] + peso;
				if(!en_cola[actual_star]) {
					cola.push(actual_star);
					en_cola[actual_star] = true;
					++conteo[actual_star];

					if(conteo[actual_star] > wormholes) return false;
				}
			}
		}
	}

	return true;
}

int main() {
	int casos;
	int stars_system, wormholes, w1, w2, peso;
	bool res;
	pair<int, int> hole;
	vector<vector<pair<int, int>>> agujeros(1001);
	vector<bool> en_cola(1001);
	vector<int> conteo(1001);
	vector<int> holes_weight(1001);

	cin >> casos;
	while(casos--) {
		cin >> stars_system >> wormholes;
		fill(agujeros.begin(), agujeros.begin() + stars_system, vector<pair<int, int>>());
		for(int i = 0; i < wormholes; ++i) {
			cin >> w1 >> w2 >> peso;
			hole.first = w2;
			hole.second = peso;
			agujeros[w1].push_back(hole);
		}

		for(int i = 0; i < stars_system; ++i) {
			en_cola[i] = false;
			conteo[i] = 0;
			holes_weight[i] = INFINITO;
		}

		res = recorridoEspacio(agujeros, en_cola, conteo, holes_weight, wormholes);
		
		if(res) cout << "not possible" << endl;
		else cout << "possible" << endl;
	}

	return 0;
}
