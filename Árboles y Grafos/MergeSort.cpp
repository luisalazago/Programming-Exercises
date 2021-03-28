#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& elementos, int l, int r, int m) {
	int n1, n2, i, j, k;
	vector<int> L, R;
	n1 = m - l + 1;
	n2 = r - m;
	for(i = 0; i < n1; i++) L.push_back(elementos[i + l]); // ?
	for(j = 0; j < n2; j++) R.push_back(elementos[j + m + 1]); // ?
	
	i = j = 0;
	for(k = l; i < n1 && j < n2; k++) {
		if(L[i] < R[j]) elementos[k] = L[i++];
		else elementos[k] = R[j++];
	}

	while(i < n1) elementos[k++] = L[i++]; // Si quedaron más elementos en L.
	while(j < n2) elementos[k++] = R[j++]; // Si quedaron más elementos en R.
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
	int cant, num;
	vector<int> elementos;

	cin >> cant;
	for(int i = 0; i < cant; i++) {
		cin >> num;
		elementos.push_back(num);
	}

	int l, r;
	l = 0;
	r = cant - 1;
	mergeSort(elementos, l, r);

	for(int i = 0; i < cant; i++) cout << elementos[i] << " ";
	cout << endl;
	return 0;
}