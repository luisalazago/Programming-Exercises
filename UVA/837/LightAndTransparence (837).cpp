#include <iostream>
#include <vector>
#include <stdio.h>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

void merge(vector<double>& elementos, int l, int r, int m) {
	int n1, n2, i, j, k;
	vector<double> L, R;
	n1 = m - l + 1;
	n2 = r - m;

	for(i = 0; i < n1; ++i) L.push_back(elementos[i + l]); 
	for(j = 0; j < n2; ++j) R.push_back(elementos[j + m + 1]); 
	
	i = j = 0;
	for(k = l; i < n1 && j < n2; ++k) {
		if(L[i] < R[j]) elementos[k] = L[i++];
		else elementos[k] = R[j++];
	}

	while(i < n1) elementos[k++] = L[i++]; 
	while(j < n2) elementos[k++] = R[j++];
}

void mergeSort(vector<double>& elementos, int l, int r) {
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
	int cases, cant_puntos, lineas;
	double x1, y1, x2, y2, r, coeficiente, suma;
	vector<double> temp, puntos;
	vector<vector<double>> coeficientes;

	cin >> cases;
	while(cases--) {
		cin >> cant_puntos;
		for(int i = 0; i < cant_puntos; ++i) {
			cin >> x1 >> y1 >> x2 >> y2 >> r;
			temp.push_back(r);
			if(x1 < x2) {
				temp.push_back(x1);
				temp.push_back(x2);
			}
			else {
				temp.push_back(x2);
				temp.push_back(x1);
			}
			coeficientes.push_back(temp);
			puntos.push_back(x1);
			puntos.push_back(x2);
			temp.clear();
		}

		int l, r;
		l = 0;
		r = puntos.size() - 1;
		mergeSort(puntos, l, r);

		lineas = 2;
		lineas += ((puntos.size() / 2) + cant_puntos) - 1;
		printf("%d\n", lineas);
		printf("-inf %.3lf 1.000\n", puntos[0]);
		for(int i = 0; i < puntos.size() - 1; ++i) {
			coeficiente = 1;
			int j = 0;
			suma = (puntos[i] + puntos[i + 1]) / 2;
			while(j < coeficientes.size()) {
				if(suma > coeficientes[j][1] && suma < coeficientes[j][2]) coeficiente *= coeficientes[j][0];
				++j;
			}
			printf("%.3lf %.3lf %.3lf\n", puntos[i], puntos[i + 1], coeficiente);
		}
		printf("%.3lf +inf 1.000\n", puntos[puntos.size() - 1]); 
		puntos.clear();
		coeficientes.clear();
		if(cases) printf("\n");
	}
	return 0;
}