#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int citys, streets, aveniues, operations, n1, n2, n3, n4, ver, ver2;
	vector<int> temp;
	vector< vector<int> > movimientos;
	vector<int>::iterator it; 

	cin >> citys;
	while(citys--) {
		cin >> streets >> aveniues >> operations;
		for(int i = 0; i < operations; i++) {
			cin >> n1 >> n2 >> n3 >> n4;
			temp.push_back(n1);
			temp.push_back(n2);
			temp.push_back(n3);
			temp.push_back(n4);
			sort(temp.begin(), temp.end());
			movimientos.push_back(temp);
			temp.clear();
		}

		ver2 = 0;
		for(int i = 0; i < operations; i++) {
			if(i == operations - 1) break;
			ver = 0;
			temp = movimientos[i + 1];
			for(int j = 0; j < 3; j += 2) {
				it = lower_bound(temp.begin(), temp.end(), movimientos[i][j]);
				if(*it == movimientos[i][j]) ver++;
				it = lower_bound(temp.begin(), temp.end(), movimientos[i][j + 1]);
				if(*it == movimientos[i][j + 1]) ver++;
			}
			if(ver == 4) ver2++;
		}

		if(ver2 == operations - 1) cout << "Yes" << endl;
		else cout << "No" << endl;
		movimientos.clear();
	}

	return 0;
}