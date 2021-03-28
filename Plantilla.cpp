#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int main() {
	int numero, numero2, numoriginal;
	set<vector<int>> res;
	set<vector<int>>::iterator it;
	vector<int> multiplos, temp;

	cin >> numero;
	while(numero) {
		numoriginal = numero;
		int k = 2;
		while(numero > 1) {
			if(numero % k == 0) {
				numero /= k;
				multiplos.push_back(k);
			}
			else ++k;
		}

		/*
		for(int i = 0; i < multiplos.size(); ++i) {
			if(i == (multiplos.size() - 1)) cout << multiplos[i] << endl;
			else cout << multiplos[i] << " ";
		}
		*/

		if(numoriginal == 1) cout << 0 << endl;
		else {
			res.insert(multiplos);
			for(int i = 0; i < multiplos.size() - 1; ++i) {
				for(int j = i; j < multiplos.size(); ++j) {
					if(j != (multiplos.size() - 1)) {
						numero2 = multiplos[j] * multiplos[j + 1];
						temp.push_back(numero2);
						++j;
					}
					else temp.push_back(multiplos[j]);
				}
				res.insert(temp);
				temp = vector<int>();
			}

			cout << res.size() << endl;
			for(it = res.begin(); it != res.end(); ++it) {
				for(int i = 0; i < (*it).size(); ++i) {
					if(i == ((*it).size() - 1)) cout << (*it)[i] << endl;
					else cout << (*it)[i] << " ";
				}
			}
		}

		multiplos.clear();
		cin >> numero;
	}

	return 0;
}