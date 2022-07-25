#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	int months_paymente, m;
	double pago, monto, depreciacion, numero, pago_mes, val, val2;
	vector<double> depreciaciones(101);

	cin >> months_paymente >> pago >> monto >> depreciacion;
	while(months_paymente >= 0) {
		for(int i = 0; i < depreciacion; ++i) {
			cin >> m >> numero;
			for(int j = m; j < 101; ++j) depreciaciones[j] = numero;
		}

		int meses = 0;
		pago_mes = monto / months_paymente;
		val = (monto + pago) * (1 - depreciaciones[meses]);
		val2 = monto;
		while(val < val2) {
			++meses;
			val2 -= pago_mes;
			val *= (1 - depreciaciones[meses]);
		}

		if(meses == 1) cout << meses << " month" << endl;
		else cout << meses << " months" << endl;

		depreciaciones.clear();
		cin >> months_paymente >> pago >> monto >> depreciacion;
	} 
	
	return 0;
}