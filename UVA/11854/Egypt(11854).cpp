#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

using namespace std;

int main() {
	FAST_IO;
	long long int a, b, c;
	bool ver;

	cin >> a >> b >> c;
	while(a) {
		ver = false;
		if(a >= b && a >= c) {
			if((b * b) + (c * c) == (a * a)) ver = true;
		}
		else if(b >= a && b >= c) {
			if((a * a) + (c * c) == (b * b)) ver = true;
		}
		else {
			if((a * a) + (b * b) == (c * c)) ver = true;
		}

		if(ver) cout << "right" << endl;
		else cout << "wrong" << endl;

		cin >> a >> b >> c;
	}
	
	return 0;
}