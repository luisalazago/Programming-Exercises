#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int averiguarRadar(int& n, int& m) {
	int radares;
	radares = (n / 3) * (m / 3);
	return radares;
}

int main() {
	int cases, n, m;

	cin >> cases;
	while(cases--) {
		cin >> n >> m;
		cout << averiguarRadar(n, m) << endl;
	}

	return 0;
}