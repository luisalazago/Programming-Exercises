#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int num, tiempo, time;
	char r[9];
	vector<int> adentro;
	priority_queue< vector<int> > baseDatos;

	cin >> r; 
	while(r[0] != '#') {
		cin >> num >> tiempo;
		num *= -1;
		tiempo *= -1;
		adentro.push_back(tiempo);
		adentro.push_back(num);
		adentro.push_back(tiempo);
		baseDatos.push(adentro);
		adentro.clear();
		cin >> r;
	}

	cin >> time;
	for(int i = time; i > 0; i--) {
		cout << baseDatos.top()[1] * -1 << endl;
		adentro = baseDatos.top();
		adentro[0] += adentro[2];
		baseDatos.pop();
		baseDatos.push(adentro);
	}
	return 0;
}