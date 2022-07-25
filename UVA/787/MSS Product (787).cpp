#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

void divAndCon(vector<int>& lista, int i, int j, int& max_num) {
	int num;
	for(int k = 0; k < j; ++k) {
		if(i + k < j) divAndCon(lista, i + k, j / 2, max_num);
		num = 1;
		while(i < j) {
			num *= lista[i];
			++i;
		}
		cout << "a " << num << endl;
		if(num > max_num) max_num = num;
	}
}

int main(int argc, char* agrv[]) {
	int num, k, max_num, temp;
	vector<int> lista;
	while(cin >> num) {
		k = 0;
		lista = vector<int>(100);
		while(num != -999999) {
			lista[k] = num;
			++k;
			cin >> num;
		}

		temp = 1;
		for(int i = 0; i < lista.size(); ++i) temp *= lista[i];
		max_num = temp;
		divAndCon(lista, 0, lista.size() / 2, max_num);
		cout << max_num << endl;
	}

	return 0;
}