#include <iostream>
#include <cstdlib>

#define INFINITO 2000000
#define endl '\n'

using namespace std;

int main() {
	bool flag;
	long long int cases, n1, n2, sum1, sum2;

	cin >> cases;
	while(cases--) {
		cin >> n1 >> n2;
		flag = true;
		sum1 = (n1 + n2) / 2;
		sum2 = (n1 - n2) / 2;
		if((n1 + n2) % 2 != 0) flag = false;
		if((n1 - n2) % 2 != 0 || sum2 < 0) flag = false;

		if(flag) cout << sum1 << " " << sum2 << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}