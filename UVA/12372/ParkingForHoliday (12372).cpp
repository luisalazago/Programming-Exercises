#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	int cases, p1, p2, p3, ver;

	cin >> cases;
	int i = 1;
	while(cases--) {
		ver = 0;
		cin >> p1 >> p2 >> p3;
		if(p1 <= 20 && p2 <= 20 && p3 <= 20) ver += 2;

		cout << "Case " << i << ": ";
		if(ver == 2) cout << "good" << endl;
		else cout << "bad" << endl;
		++i;
	}
	
	return 0;
}