#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	long long cases, numero, cantidad, numero3;
	bool ver;
	string temp, temp2;

	cin >> cases;
	while(cases--) {
		cin >> numero;
		cantidad = 0;
		temp = to_string(numero);
		temp2 = temp;
		reverse(temp2.begin(), temp2.end());
		ver = true;
		while(temp != temp2 || ver) {
			if(ver) ver = false;
			stringstream numero2(temp2);
			numero2 >> numero3;
			numero += numero3;
			temp = to_string(numero);
			temp2 = temp;
			reverse(temp2.begin(), temp2.end());
			++cantidad; 
		}
		cout << cantidad << " " << temp << endl;
	}

	return 0;
}