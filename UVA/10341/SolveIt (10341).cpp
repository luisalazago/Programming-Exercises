#include <iostream>
#include <cstdio>
#include <math.h>

#define definitoria(p, q, r, s, t, u) ((p * exp(-1)) + (q * sin(1)) + (r * cos(1)) + (s * tan(1)) + t + u) 

using namespace std;

int main() {
	int p, q, r, s, t, u, ver;
	double left, right;
	double resultado, m;

	while(cin >> p >> q >> r >> s >> t >> u) {
		left = 0.0;
		right = 1.0;
		ver = 0;
		for(int i = 0; i < 30; i++) {
			m = (left + right) / 2;
			resultado = (p * exp(-m)) + (q * sin(m)) + (r * cos(m) + (s * tan(m)) + (t * pow(m, 2)) + u);
			if(resultado > 0) left = m;
			else right = m;
		}

		if(definitoria(p, q, r, s, t, u) > 0.000000001 || p + r + u < 0) {
			cout << "No solution" << endl;
			ver++;
		}
		if(ver == 0) printf("%.4f\n", left);
	}

	return 0;
}