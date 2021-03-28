#include <iostream>
#include <queue>

using namespace std;

int main() {
	int cases, cant_trabajos, posicion_trabajo, trabajo, ver, contador, temp2, ver2;
	queue<int> trabajos;
	priority_queue<int> temp;

	cin >> cases;
	while(cases--) {
		cin >> cant_trabajos >> posicion_trabajo;
		contador = 1;
		for(int i = 0; i < cant_trabajos; i++) {	
			cin >> trabajo;
			temp.push(trabajo);
			if(i == posicion_trabajo) trabajo *= -1;
			trabajos.push(trabajo);
		}

		ver = 1;
		ver2 = 0;
		temp2 = 5000;
		while(!temp.empty() && ver != 0) {
			if(trabajos.front() < 0) {
				temp2 = trabajos.front();
				trabajos.front() *= - 1;
				ver2 = 1;
			}
			if(trabajos.front() == temp.top()) {
				if(temp2 < 0) {
					cout << contador << endl;
					ver = 0;
				}
				else {
					contador++;
					trabajos.pop();
					temp.pop();
				}
			}
			else {
				if(ver2 == 1) {
					trabajos.front() *= -1;
					ver2 = 0;
					temp2 = 5000;
				}
				trabajo = trabajos.front();
				trabajos.push(trabajo);
				trabajos.pop();
			}
		}
		if(trabajos.size() > 0) while(!trabajos.empty()) trabajos.pop();
		if(temp.size() > 0) while(!temp.empty()) temp.pop();
	}
	return 0;
}

/*La complejidad de este algoritmo es O(n^2), ya que se compara un elemento de
  la cola con los otros de la otra cola, este algoritmo según la cantidad casos 
  elevada la complejidad del algoritmo no sobrepasa el límite estblecido por UVA
  que es 10^9*/