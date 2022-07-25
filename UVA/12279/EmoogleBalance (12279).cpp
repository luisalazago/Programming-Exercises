#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	int cant, numero, emoogle;
	vector<int> emoogle_numbers;

	cin >> cant;
	int j = 1;
	while(cant) {
		for(int i = 0; i < cant; ++i) {
			cin >> numero;
			emoogle_numbers.push_back(numero);
		}
		cout << "Case " << j << ": ";
		emoogle = 0;
		for(int i = 0; i < cant; ++i) {
			if(emoogle_numbers[i] > 0) emoogle++;
			else emoogle--; 
		}
		cout << emoogle << endl;
		emoogle_numbers.clear();
		j++;
		cin >> cant;
	}
	return 0;
}