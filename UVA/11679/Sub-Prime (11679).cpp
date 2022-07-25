#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	int bancos, debenture, deudor, creditor, numero, ver, deuda;
	vector<int> credito;

	cin >> bancos >> debenture;
	while(bancos && debenture) {
		for(int i = 0; i < bancos; ++i) {
			cin >> numero;
			credito.push_back(numero);
		}

		for(int i = 0; i < debenture; ++i) {
			cin >> deudor >> creditor >> deuda;
			credito[deudor - 1] -= deuda;
			credito[creditor - 1] += deuda;
 		}

 		ver = 1;
		for(int i = 0; i < bancos; ++i) if(credito[i] < 0) ver = 0;

		if(ver) cout << "S" << endl;
		else cout << "N" << endl; 

		credito.clear();
		cin >> bancos >> debenture;
	}
	return 0;
}