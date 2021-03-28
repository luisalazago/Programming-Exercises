#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

void merge(vector<int>& elementos, int l, int r, int m) {
	int n1, n2, i, j, k;
	vector<int> L, R;
	n1 = m - l + 1;
	n2 = r - m;

	for(i = 0; i < n1; ++i) L.push_back(elementos[i + l]);
	for(i = 0; i < n2; ++i) R.push_back(elementos[i + m + 1]);

	i = j = 0;
	for(k = l; i < n1 && j < n2; ++k) {
		if(L[i] < R[j]) elementos[k] = L[i++];
		else elementos[k] = R[j++];
	}

	while(i < n1) elementos[k++] = L[i++];
	while(j < n2) elementos[k++] = R[j++];
}

void mergeSort(vector<int>& elementos, int l, int r) {
	int m;
	if(l < r) {
		m = (l + r) / 2;
		mergeSort(elementos, l, m);
		mergeSort(elementos, m + 1, r);
		merge(elementos, l, r, m);
	}
}

int main() {
	FAST_IO;
	int cant, numero;
	vector<int> years;

	cin >> cant;
	while(cant) {
		for(int i = 0; i < cant; ++i) {
			cin >> numero;
			years.push_back(numero);
		}

		int l = 0, r = cant - 1;
		mergeSort(years, l, r);

		for(int i = 0; i < cant; ++i) {
			if(i != cant - 1) cout << years[i] << " ";
			else cout << years[i];
		}
		cout << endl;
		years.clear();

		cin >> cant;
	}
	return 0;
}