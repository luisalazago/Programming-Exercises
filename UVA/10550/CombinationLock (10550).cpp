#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define lockP 9
#define girada 1080
#define reloj 40

using namespace std;

int main() {
	int posicion_incial, p1, p2, p3, sumatoria;

	cin >> posicion_incial >> p1 >> p2 >> p3;
	while(p1 != 0 || p2 != 0 || p3 != 0 || posicion_incial != 0) {
		sumatoria = girada;
		sumatoria += ((posicion_incial - p1 + reloj) % reloj + (p2 - p1 + reloj) % reloj + (p2 - p3 + reloj) % reloj) * lockP;
		cout << sumatoria << endl;
		cin >> posicion_incial >> p1 >> p2 >> p3;
	} 

	return 0;
}