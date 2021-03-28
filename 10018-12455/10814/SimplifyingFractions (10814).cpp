#include <iostream>
#include <stdio.h>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	long long int cases, n1, n2;
	char div[2], numero[50];

	cin >> cases;
	while(cases--) {
		cin >> n1 >> div[0] >> n2;
		long long int i = 2;
		while(i <= n1 && i <= n2) {
			if(n1 % i == 0 && n2 % i == 0) {
				n1 /= i;
				n2 /= i;
			}
			if(n1 == n2) break;
			else {
				sprintf(numero, "%lld", n1);
				string temp = numero;
				if(temp[temp.size() - 1] == 0 || temp[temp.size() - 1] == 2 || temp[temp.size() - 1] == 4 || temp[temp.size() - 1] == 6 || temp[temp.size() - 1] == 8) i += 2;
				if(temp[temp.size() - 1] == 0 || temp[temp.size() - 1] == 5) i += 5;
				else i += 3;
			}
		}

		while(i <= n1 && i <= n2) {
			if(n1 % i == 0 && n2 % i == 0) {
				n1 /= i;
				n2 /= i;
			}
			if(n1 == n2) break;
			else {
				sprintf(numero, "%lld", n2);
				string temp = numero;
				if(temp[temp.size() - 1] == 0 || temp[temp.size() - 1] == 2 || temp[temp.size() - 1] == 4 || temp[temp.size() - 1] == 6 || temp[temp.size() - 1] == 8) i += 2;
				if(temp[temp.size() - 1] == 0 || temp[temp.size() - 1] == 5) i += 5;
				else i += 3;
			}
		}

		cout << n1 << " " << div[0] << " " << n2 << endl;
	}

	return 0;
}