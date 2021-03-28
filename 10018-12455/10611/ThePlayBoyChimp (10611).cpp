#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cantidad_ladys, cantidad_machos;
	long long cant;
	vector<long long> ladys;
	vector<long long> machos;
	vector<long long>::iterator it;

	cin >> cantidad_ladys;
	for(int i = 0; i < cantidad_ladys; i++) {
		cin >> cant;
		ladys.push_back(cant);
	}
	cin >> cantidad_machos;
	for(int i = 0; i < cantidad_machos; i++) {
		cin >> cant;
		machos.push_back(cant);
	}

	for(int i = 0; i < cantidad_machos; i++) {
		it = lower_bound(ladys.begin(), ladys.end(), machos[i]);
		it--;

		if(it == ladys.begin() - 1) cout << "X ";
		else cout << *it << " ";

		it = upper_bound(ladys.begin(), ladys.end(), machos[i]);
		
		if(it == ladys.end()) cout << "X" << endl;
		else cout << *it << endl;	
	}
	return 0;
}