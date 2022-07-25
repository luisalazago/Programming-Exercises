#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& miles, int l, int r, int m) {
	int n1, n2, i, j, k;
	vector<int> L, R;
	n1 = m - l + 1;
	n2 = r - m;

	for(i = 0; i < n1; i++) L.push_back(miles[l + i]);
	for(i = 0; i < n2; i++) R.push_back(miles[m + i + 1]);

	i = j = 0;
	for(k = l; i < n1 && j < n2; k++) {
		if(L[i] < R[j]) miles[k] = L[i++];
		else miles[k] = R[j++];
	}

	while(i < n1) miles[k++] = L[i++];
	while(j < n2) miles[k++] = R[j++];
}

void mergeSort(vector<int>& miles, int l, int r) {
	int m;
	if(l < r) {
		m = (l + r) / 2;
		mergeSort(miles, l, m);
		mergeSort(miles, m + 1, r);
		merge(miles, l, r, m);
	}
}

int main() {
	int campers, nights, mile, l, r, ver, resto, m;
	vector<int> miles;

	while(cin >> campers >> nights) {
		nights++;
		for(int i = 0; i < campers + 1; i++) {
			cin >> mile;
			miles.push_back(mile);
		}

		l = 0;
		r = campers + 1;
		mergeSort(miles, l, r);

		l = 0;
		r = 1000000;

		while(l <= r) {
			m = (l + r) / 2;
			ver = resto = 0;
			for(int i = 0; i <= miles.size(); i++) {
				if(miles[i] > m) break;
				if(miles[i] + resto > m) {
					resto = miles[i];
					ver++;
				}
				else resto += miles[i];
			}
			if(resto) ver++;
			if(ver <= nights) r = m - 1;
			else l = m + 1;
			// cout << r << " ";
		}
		cout << endl;

		cout << ++r << endl;  
		miles.clear();
	}
	return 0;
} 